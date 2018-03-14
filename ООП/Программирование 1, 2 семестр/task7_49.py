"""
Шишмарев Павел. Вариант №14.
Задание 7. Задача 49.
Дано действительное число h. Выяснить, имеет ли квадратное уравнение действительные корни, если...
Формулы a, b, c см. в задачнике.
Если корни сущ-ют, найти их.
"""
from math import sqrt, sin, cos


def tg(x):
  return sin(x)/cos(x)


def _a(h):
  return sqrt((sin(8*h)+17)/(1-sin(4*h)*(h**2+18))**2)


def _b(a, h):
  return 1-sqrt(3/(3+abs(tg(a*h**2)-sin(a*h))))


def _c(a, b, h):
  return a*h**2*sin(b*h)+b*h**3*cos(a*h)


h = float(input("Введите число h: "))
a = _a(h)
b = _b(a, h)
c = _c(a, b, h)
D = b**2 - 4*a*c

if D < 0:
  print("Корней нет.")
else:
  print("x1 = {0:.2f}".format((-b+sqrt(D))/2*a))
  if D > 0:
    print("x2 = {0:.2f}".format((-b-sqrt(D))/2*a))

