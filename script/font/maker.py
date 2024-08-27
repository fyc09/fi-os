import font
import util
import os
import ctypes
import sys

jzcnfont = font.make_font_Guanzhi()
suncnfont = font.make_font_Simsun()

fs = util.make_fs([jzcnfont, suncnfont])

with open("out.bin", "wb") as f:
    f.write(fs)
