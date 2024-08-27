import matplotlib.pyplot as plt
import matplotlib
import numpy as np

matplotlib.use("TkAgg")

with open("log.txt", "r") as f:
    s = f.read()

s = s.split(" ")
s = [int(n, base=16) for n in s if n]
# s = np.log2(s)
# infs = np.isinf(s)
# s[infs] = -1

# x = s[:-1] - s[1:]

plt.plot(s, color="red")
plt.show()
plt.savefig("out")
