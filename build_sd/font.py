from bdfparser import Font
from util import *
from itertools import batched


def make_font_Guanzhi():
    font = Font("Guanzhi.bdf")

    file = b""

    chrs = []

    for c in font.iterglyphs():
        try:
            char = c.chr()
        except Exception:
            print("error")
            continue
        chrs.append(char)

    chrs.sort()

    anchors = {}

    for g in batched(chrs, 36):
        file += itob(ord(g[-1]), 3)
        anchors[g[0]] = len(file)
        file += b"\x00" * 5
    file += b"\x00" * 8

    for a in chrs:
        data = font.draw(a).todata()
        if a in anchors:
            file = set_bytes(file, anchors[a], itob(len(file) - anchors[a], 5))

        matrix = b""
        for i in range(8):
            byte = 0
            for j in range(8):
                byte <<= 1
                byte |= int(data[7 - j][i])
            matrix += byte.to_bytes(1, "little")

        file += ord(a).to_bytes(3, "little")
        file += matrix

    with open("font.bin", "wb") as f:
        f.write(file)

    font_file = File("gzcnfont", file)

    return font_file


def make_font_Simsun():
    font = Font("Simsun-15.bdf")

    file = b""

    chrs = []

    for c in font.iterglyphs():
        try:
            char = c.chr()
        except Exception:
            print("error")
            continue
        chrs.append(char)

    chrs.sort()

    anchors = {}

    for g in batched(chrs, 36):
        file += itob(ord(g[-1]), 3)
        anchors[g[0]] = len(file)
        file += b"\x00" * 5
    file += b"\x00" * 8

    for a in chrs:
        data = font.draw(a).todata()
        if a in anchors:
            file = set_bytes(file, anchors[a], itob(len(file) - anchors[a], 5))

        matrix = b""

        matrix += itob(0, 1)
        for i in range(14):
            byte = 0
            for j in range(7):
                byte <<= 1
                byte |= int(data[6 - j][i])
            byte <<= 1
            matrix += byte.to_bytes(1, "little")
        matrix += itob(0, 2)
        for i in range(14):
            byte = 0
            for j in range(7):
                byte <<= 1
                byte |= int(data[13 - j][i])
            matrix += byte.to_bytes(1, "little")
        matrix += itob(0, 1)

        file += ord(a).to_bytes(3, "little")
        file += matrix

    with open("font.bin", "wb") as f:
        f.write(file)

    font_file = File("suncnfont", file)

    return font_file
