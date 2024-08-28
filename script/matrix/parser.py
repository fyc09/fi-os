import textwrap
import sys
from PIL import Image, ImageOps
import numpy as np
import itertools

infofile = sys.argv[1]
picfile = sys.argv[2]
outfile = sys.argv[3]

with open(infofile) as f:
    s = f.read()
s = s.split("\n")

img = Image.open(picfile)

resources = {}



def batched(iterable, n, *, strict=False):
    if n < 1:
        raise ValueError('n must be at least one')
    iterator = iter(iterable)
    while batch := tuple(itertools.islice(iterator, n)):
        if strict and len(batch) != n:
            raise ValueError('batched(): incomplete batch')
        yield batch
itertools.batched = batched

def declare_parents(cmd, parents):
    cmd.parents = parents

def cmd_deco(cls):
    name = cls.__name__.upper()
    obj = Cmd(cls, [], name)
    cmds[name] = obj
    return obj


class Cmd:
    def __init__(self, cls, parents, name):
        self.cls: type = cls
        self.parents: list[Cmd] = parents
        self.name: str = name
    
class CmdObj:
    def __init__(self, cmd, lineno):
        self.cmd: Cmd = cmd
        self.lineno: int = lineno
        self.child_cmd: list[CmdObj] = []
        self.child_val: list[any] = []
    
    def add_child_cmd(self, cmd):
        self.child_cmd.append(cmd)
    
    def add_child_val(self, val):
        self.child_val.append(val)
    
    def gen_code(self):
        return self.cmd.cls.gen_code(self, self)
    
    def get_subcmd(self, cmd: Cmd):
        for co in self.child_cmd:
            if co.cmd.name == cmd.name:
                return co


cmds: dict[str, Cmd] = {}


@cmd_deco
class Document:
    def __init__(self) -> None:
        raise ValueError("Do not write anything directly under Document element")
    
    def gen_code(self, cmdobj: CmdObj):
        name = 'unset'
        content = []
        for co in cmdobj.child_cmd:
            if co.cmd.name == "NAME":
                name = co.child_val[0].name
            else:
                if hasattr(co.cmd.cls, 'gen_code'):
                    content.append(co.gen_code())
                else:
                    print(co.cmd.name)

        content = '\n\n'.join(content)

        code = textwrap.dedent(
            '/* THIS FILE IS AUTO GENERATED. DO NOT EDIT. */\n'
            '#include "oled.h"\n'
            '#include <stdint.h>\n'
            '#include <stdbool.h>\n'
            '#include "system.h"\n\n'

            f'#ifndef {name.upper()}_PICS_H\n'
            f'#define {name.upper()}_PICS_H\n\n'

            f'{content}\n\n'

            '#endif\n'
        )
        return code


@cmd_deco
class Resources:
    def __init__(self, x, y, w, h, t, r, b, l, name) -> None:
        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.t = t
        self.r = r
        self.b = b
        self.l = l
        self.name = name
    
    def gen_code(self, cmdobj: CmdObj):
        code = []
        for val in cmdobj.child_val:
            x = int(val.x)
            y = int(val.y)
            w = int(val.w)
            h = int(val.h)
            t = int(val.t)
            r = int(val.r)
            b = int(val.b)
            l = int(val.l)
            name = val.name

            part = img.crop((x, y, x + w, y + h))
            part = ImageOps.expand(part, (l, t, r, b), fill='white')
            if part.size[1] % 8 != 0:
                print(f"At {infofile}:{val.lineno}")
                raise ValueError(f"Height must be a multiple of 8. Size is {part.size}")
            arr: np.ndarray[bool] = np.array(part)
            arrs = batched(arr, 8)
            arr = [np.array(arr[::-1]).transpose((1, 0)) for arr in arrs]
            arr = np.concat(arr)
            arr = arr.flatten()

            values: list[str] = []
            for i in batched(arr, 8):
                values.append(int(''.join(map(str, map(int, i))), 2))

            matrix = ', '.join(hex(value) for value in values)

            code.append(f'const uint8_t _{name}_DATA[] = {{{matrix}}};\nfi_matrix_t {name} = {{_{name}_DATA, {w}, {h}}};')

        code = '\n\n'.join(code)

        return code
        
@cmd_deco
class List:
    def __init__(self) -> None:
        raise ValueError("Do not write anything directly under List element")
    
    def gen_code(self, cmdobj: CmdObj):
        nameobj = cmdobj.get_subcmd(Name)
        itemsobj = cmdobj.get_subcmd(Items)
        typeobj = cmdobj.get_subcmd(Type)
        if nameobj is None or itemsobj is None or typeobj is None:
            print(f"At {infofile}:{cmdobj.lineno}")
            raise ValueError("List element must have Name, Items and Type element")

        items = itemsobj.gen_code()
        return f"{typeobj.child_val[0].name} {nameobj.child_val[0].name}[] = {{{items}}};"

    

@cmd_deco
class Items:
    def __init__(self, name) -> None:
        self.name = name

    def gen_code(self, cmdobj: CmdObj):
        items = []
        for val in cmdobj.child_val:
            items.append(val.name)
        return ', '.join(items)


@cmd_deco
class Type:
    def __init__(self, name) -> None:
        self.name = name


@cmd_deco
class Layer:
    def __init__(self) -> None:
        raise ValueError("Do not write anything directly under Layer element")
    
    def gen_code(self, cmdobj: CmdObj):
        name = cmdobj.get_subcmd(Name)
        params = cmdobj.get_subcmd(Params)
        parts = cmdobj.get_subcmd(Parts)
        defs = cmdobj.get_subcmd(Defs)
        if name is None or parts is None:
            print(f"At {infofile}:{cmdobj.lineno}")
            raise ValueError("Layer element must have Name, Params and Parts element")
        
        name_code = name.gen_code()
        if params is None:
            params_code = ""
        else:
            params_code = params.gen_code()
        
        # body = []

        # for part in parts.child_val:
        #     part_code = part.gen_code()
        #     body.append(part_code)
        
        # body = textwrap.indent('\n'.join(body), ' ' * 4)

        body = parts.gen_code()

        code = (
            f"void {name_code}({params_code}) {{\n"
            f"{textwrap.indent(body, ' ' * 4)}\n"
            f"}}\n"
        )
        return code


@cmd_deco
class Params:
    def __init__(self, type, name) -> None:
        self.type = type
        self.name = name

    def gen_code(self, cmdobj: CmdObj):
        TYPE_TO_CTYPE = {
            "number": "uint8_t",
            "bool": "bool",
            "string": "const char*"
        }

        code = []
        for val in cmdobj.child_val:
            ctype = TYPE_TO_CTYPE[val.type]
            code.append(f"{ctype} {val.name}")
        return ', '.join(code)


@cmd_deco
class Defs:
    def __init__(self, name, value) -> None:
        self.name = name
        self.value = value


@cmd_deco
class If:
    def __init__(self, condition) -> None:
        self.condition = condition
    
    def gen_code(self, cmdobj: CmdObj):
        condition = cmdobj.child_val[0].condition
        body = textwrap.indent(cmdobj.get_subcmd(Parts).gen_code(), ' ' * 4)
        other_ctrl = cmdobj.get_subcmd(Else) or cmdobj.get_subcmd(Elif)
        other_ctrl_code = ' ' + other_ctrl.gen_code() if other_ctrl else ""
        return (
            f"if ({condition}) {{\n"
            f"{body}\n"
            f"}}{other_ctrl_code}"
        )

@cmd_deco
class Elif:
    def __init__(self, condition) -> None:
        self.condition = condition
    
    def gen_code(self, cmdobj: CmdObj):
        condition = cmdobj.child_val[0].condition
        body = textwrap.indent(cmdobj.get_subcmd(Parts).gen_code(), ' ' * 4)
        other_ctrl = cmdobj.get_subcmd(Else) or cmdobj.get_subcmd(Elif)
        other_ctrl_code = ' ' + other_ctrl.gen_code() if other_ctrl else ""
        return (
            f"else if ({condition}) {{\n"
            f"{body}\n"
            f"}}{other_ctrl_code}"
        )

@cmd_deco
class Else:
    def __init__(self) -> None:
        raise ValueError("Do not use Else")
    
    def gen_code(self, cmdobj: CmdObj):
        body = ''.join(map(lambda x: x.gen_code(), cmdobj.child_cmd))
        return (
            f"else {{\n"
            f"{body}\n"
            f"}}"
        )

@cmd_deco
class Parts:
    def __init__(self, x, y, width, height, name) -> None:
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.name = name
    
    def gen_code(self, cmdobj: CmdObj):
        code = []

        for co in cmdobj.child_val:
            if co.width == "_":
                co.width = f"{co.name}.width"
            if co.height == "_":
                co.height = f"{co.name}.height"
            code.append(f"fi_OLED_drawPic({co.x}, {co.y}, {co.width}, {co.height}, {co.name}.matrix);")

        for co in cmdobj.child_cmd:
            if co.cmd.name == "IF":
                code.append(co.gen_code())

        return '\n'.join(code)

@cmd_deco
class Name:
    def __init__(self, name) -> None:
        self.name = name
    
    def gen_code(self, cmdobj: CmdObj):
        return cmdobj.child_val[0].name


declare_parents(Resources, [Document])
declare_parents(List, [Document])
declare_parents(Items, [List])
declare_parents(Type, [List])
declare_parents(Layer, [Document])
declare_parents(Params, [Layer])
declare_parents(Defs, [Layer])
declare_parents(If, [Parts])
declare_parents(Elif, [If])
declare_parents(Else, [If, Elif])
declare_parents(Parts, [Layer, If, Elif, Else])
declare_parents(Name, [List, Layer, Document])

stack: list[CmdObj] = [CmdObj(Document, 1)]
for lineno, line in enumerate(s):
    if not line:
        continue

    if line.startswith('['):
        # Is cmd
        cmdname = line.removeprefix('[').removesuffix(']')
        if cmdname == "END":
            if stack[-1].cmd.name in ["IF", "ELIF", "ELSE"]:
                while len(stack) > 0 and stack[-1].cmd.name in ["IF", "ELIF", "ELSE"]:
                    stack.pop()
            else:
                stack.pop()
            continue
        cmd = cmds[cmdname]
        while len(stack) > 0 and stack[-1].cmd not in cmd.parents:
            stack.pop()
        if len(stack) == 0:
            print(f"At {infofile}:{lineno + 1}")
            raise Exception(f'Line {lineno}: No parent for command {cmdname}')
        stack.append(CmdObj(cmd, lineno + 1))
        stack[-2].add_child_cmd(stack[-1])
        for i in stack:
            print(i.cmd.name, end=">")
        print()
    else:
        args = line.split('\t')
        try:
            value = stack[-1].cmd.cls(*args)
        except Exception as e:
            print(f"At {infofile}:{lineno + 1}")
            raise e
        value.lineno = lineno + 1
        stack[-1].add_child_val(value)

root = stack[0]

with open(outfile, 'w') as f:
    f.write(root.gen_code())
