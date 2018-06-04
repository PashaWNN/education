"""
Шишмарев Павел. Вариант №14.
Задание 13. Задача 115ж.
Найти алгебраическую сумму по формуле(см. задачник)
"""
from math import factorial as f

n = int(input('Введите n: '))
res = 0
for i in range(1, n+1):
  r = 0
  for j in range(1, n+2): r+=1/j
  res += f(i)/r

print('Результат: {0:.2f}'.format(res))
