from bitmap import Bitmap
from random import choice, seed

BLACK = (0,0,0)
WHITE = (255,255,255)

class Automata():

  def __init__(s, rule, width=512):
    s.cells = [False]*width
    s.rule = rule
    rule_bin = bin(rule)[2:].rjust(8, '0')
    s.rule_bin = []
    for i in range(0, 8):
      s.rule_bin.append(True if rule_bin[i] == '1' else False)
  
  def random(s):
    for i in range(0, len(s.cells)):
      s.cells[i] = choice((True, False))

  def do_gen(s):
    ncells = [False] * len(s.cells)
    for i in range(0, len(s.cells)):
      left = i-1 if i > 0 else len(s.cells)-1
      right = i+1 if i < len(s.cells)-1 else 0
      left = s.cells[left]
      right = s.cells[right]
      center = s.cells[i]
      ncells[i] = s._generate(left, center, right, s.rule_bin)
    s.cells = ncells

  def _generate(s, l, c, r, rule):
    val = int(l)*100 + int(c) * 10 + int(r)
    if val == 111:
      return rule[0]
    elif val == 110:
      return rule[1]
    elif val == 101:
      return rule[2]
    elif val == 100:
      return rule[3]
    elif val ==  11:
      return rule[4]
    elif val ==  10:
      return rule[5]
    elif val ==   1:
      return rule[6]
    elif val ==   0:
      return rule[7]


def main():
  width = 512
  gens  = 512
  seed()
  a = Automata(int(input('Введите правило: ')))
  mode = input('Режим: из одной точки p, случайное заполнение r: ')
  if mode == 'r':
    a.random()
  elif mode == 'p':
    a.cells[width//2]=True
  else:
    print('Неправильный режим')
  b = Bitmap(width=width, height=gens)
  for gen in range(0, gens):
    for i in range(0, width):
      b.setPixel(i, gen, BLACK if a.cells[i] else WHITE)
    a.do_gen()
  b.write('file.bmp')

if __name__=='__main__':
  main()
