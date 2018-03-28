"""
Шишмарев Павел. Вариант №14.
Задание 11. Задача 80.
Дано действительное число х, вычислить x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + x^13/13!
"""
from math import factorial as f

x = float(input('Введите х: '))

lastFac = 2*3
res = x
for i in range(3, 140, 4):

  res -= x**i/f(i)+x**i+2/f(i+2)
  lastFac = 

print('Результат: {0:.8f}'.format(res))

