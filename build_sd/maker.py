import font
import util
import os
import ctypes
import sys

# jzcnfont = font.make_font_Guanzhi()
# suncnfont = font.make_font_Simsun()

# fs = util.make_fs([jzcnfont, suncnfont])

# with open("out.bin", "wb") as f:
#     f.write(fs)

ARGS = "iflag=dsync oflag=dsync if=/d/code/c/fi-os/build_sd/out.bin of=/dev/sdb"

ctypes.windll.shell32.ShellExecuteW(None, "runas", "dd", ARGS, None, 1)
