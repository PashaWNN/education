"""
Шишмарев Павел. Вариант №14.
Задание 26. Задача 758e.
Дано действительное число х. Вычислить с точностью 10-6(см. задачник)
"""
from math import sqrt

x = float(input('Х: '))

k = 0
s = 0
e = 1e-6

while True:
  k += 1
  i = x / (k**3 + k * sqrt(abs(x)) + 1)
  s += i
  if i < e:
    break

print('Результат: %.2f' % s)


