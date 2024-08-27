import sys
from PIL import Image, ImageOps
import numpy as np
import itertools

def batched(iterable, n, *, strict=False):
    if n < 1:
        raise ValueError('n must be at least one')
    iterator = iter(iterable)
    while batch := tuple(itertools.islice(iterator, n)):
        if strict and len(batch) != n:
            raise ValueError('batched(): incomplete batch')
        yield batch

itertools.batched = batched

infofile = sys.argv[1]
picfile = sys.argv[2]
outfile = sys.argv[3]
projname = sys.argv[4]

with open(infofile, 'r') as f:
    info = f.read()

info = info.split('\n')
for i in range(len(info)):
    info[i] = info[i].split(':')
    info[i] = (int(info[i][0]), int(info[i][1]), int(info[i][2]), int(info[i][3]), info[i][4])

pic = Image.open(picfile)


headfile = f'/* THIS FILE IS AUTO GENERATED. DO NOT EDIT. */\n#include <stdint.h>\n#include "system.h"\n\n#ifndef {projname.upper()}_PICS_H\n#define {projname.upper()}_PICS_H\n\n'
for x, y, w, h, name in info:
    part = pic.crop((x, y, x + w, y + h))
    if h % 8 != 0:
        part = ImageOps.expand(part, (0, 0, 0, 8 - h % 8), fill='white')
    arr: np.ndarray[bool] = np.array(part)
    arrs = itertools.batched(arr, 8)
    arr = [np.array(arr[::-1]).transpose((1, 0)) for arr in arrs]
    arr = np.concat(arr)
    arr = arr.flatten()

    values: list[str] = []
    for i in itertools.batched(arr, 8):
        values.append(int(''.join(map(str, map(int, i))), 2))

    if 0 < len(values) % 12 < 6:
        matrix = '\n'.join(' ' * 4 + ', '.join(f'0x{val:02x}' for val in line) + ',' for line in itertools.batched(values, 11))
    else:
        matrix = '\n'.join(' ' * 4 + ', '.join(f'0x{val:02x}' for val in line) + ',' for line in itertools.batched(values, 12))

    headfile += f'const uint8_t _{name}_DATA[] = {{\n{matrix}\n}};\nfi_matrix_t {name} = {{_{name}_DATA, {w}, {h}}};\n\n'

headfile += '#endif\n'

with open(outfile, 'w') as f:
    f.write(headfile)
