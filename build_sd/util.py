class File:
    def __init__(self, name: str, data: bytes):
        self.name = name
        self.data = data
        self.index_address = 0


def itob(num: int, length: int):
    return num.to_bytes(length, "little")


def btoi(data: bytes):
    return int.from_bytes(data, "little")


def set_bytes(target: bytes, index: int, value: bytes):
    return target[:index] + value + target[index + len(value) :]


def get_bytes(target: bytes, index: int, length: int):
    return target[index : index + length]


def make_fs(files: list[File]):
    img = b""

    files += [File("", b"")]

    for f in files:
        encoded_name = f.name.encode("ascii")
        if len(encoded_name) > 11:
            raise ValueError(
                f"File name too long. {f.name} is {len(encoded_name)} "
                "bytes long, exceeding 11 bytes."
            )
        encoded_name = encoded_name.ljust(11, b"\x00")
        f.index_address = len(img)
        img += encoded_name + itob(0, 5)

    for f in files:
        addr = f.index_address + 11
        img = set_bytes(img, addr, itob(len(img) - addr, 5))
        img += f.data

    return img
