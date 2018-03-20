import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches
import matplotlib.colors as cls
import random
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-d", "--depth", type=int, default=3,
                    help="Specify recursion depth.(default 3)")
parser.add_argument("-s", "--show", action='store_true',
                    help="Show squares upside down.")
parser.add_argument("-n", "--not-optimized", dest='nopt', action='store_true',
                    help="Don't optimize.")
parser.add_argument("-p", "--paint", type=str, default=None,
                    help="Specify color")
args = parser.parse_args()


def square(depth, coord=(0, 0), i=1, size=50, corner=None):
  side = (size/2)/i
  a = (coord[0]-side, coord[1]-side)
  b = (coord[0]+side, coord[1]-side)
  c = (coord[0]+side, coord[1]+side)
  d = (coord[0]-side, coord[1]+side)
  if args.nopt: corner=None
  result = [(a, b, c, d),]
  if i<depth:
    if not corner=='lb': result += square(depth, a, i+1, size/1.5, 'ru')
    if not corner=='rb': result += square(depth, b, i+1, size/1.5, 'lu')
    if not corner=='ru': result += square(depth, c, i+1, size/1.5, 'lb')
    if not corner=='lu': result += square(depth, d, i+1, size/1.5, 'rb')
  return result

lst = square(depth=args.depth)

colors = [
    '#f97306',
    '#95d0fc',
    '#c79fef',
    '#89fe05',
    '#ff796c',
]
codes = [
    Path.MOVETO,
    Path.LINETO,
    Path.LINETO,
    Path.LINETO,
    Path.CLOSEPOLY
]
paths = []
if not args.show: lst = lst[::-1]
for s in lst:
    verts = []
    verts.append((s[0][0], s[0][1]))
    verts.append((s[1][0], s[1][1]))
    verts.append((s[2][0], s[2][1]))
    verts.append((s[3][0], s[3][1]))
    verts.append((s[0][0], s[0][1]))
    paths.append(Path(verts, codes))
paths.append(Path([(0, 0)], [Path.MOVETO,]))

fig = plt.figure()
ax = fig.add_subplot(111)
for i in range(0, len(paths)-1):
    if args.paint: 
      fc = args.paint
    else:
      fc = colors[random.randrange(0, 4)]
    patch = patches.PathPatch(paths[i], facecolor=fc, lw=2)
    ax.add_patch(patch)
ax.set_xlim(-100,100)
ax.set_ylim(-100,100)
plt.show()
