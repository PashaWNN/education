import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches
import matplotlib.colors as cls
import re
import random

f = open("result.txt", "r")
codes = [
    Path.MOVETO,
    Path.LINETO,
    Path.LINETO,
    Path.LINETO,
    Path.CLOSEPOLY,
]
colors = [
    '#f97306',
    '#95d0fc',
    '#c79fef',
    '#89fe05',
    '#ff796c',
]
paths = []
for line in f:
    verts = []
    mo = re.search(
        r'\(([0-9\.-]+), ([0-9\.-]+)\) \(([0-9\.-]+), ([0-9\.-]+)\) \(([0-9\.-]+), ([0-9\.-]+)\) \(([0-9\.-]+), ([0-9\.-]+)\)',
        line)

    verts.append((float(mo.group(1)), float(mo.group(2))))
    verts.append((float(mo.group(3)), float(mo.group(4))))
    verts.append((float(mo.group(5)), float(mo.group(6))))
    verts.append((float(mo.group(7)), float(mo.group(8))))
    verts.append((float(mo.group(1)), float(mo.group(2))))
    paths.append(Path(verts, codes))
    print(verts)

fig = plt.figure()
ax = fig.add_subplot(111)
for i in range(0, len(paths)-1):
    fc = colors[random.randrange(0, 4)]
    patch = patches.PathPatch(paths[i], facecolor=fc, lw=2)
    ax.add_patch(patch)
ax.set_xlim(-20,20)
ax.set_ylim(-20,20)
plt.show()
