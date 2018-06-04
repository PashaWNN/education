#!/usr/bin/python3
"""
Шишмарев Павел. Вариант №14.
Задание 23. Задача 320.
Вычислить по формуле(см. задачник)
"""
sum1 = 0
for k in range(1, 11):
  sum2 = 0
  for l in range(1, 16):
    sum2 += (k - l)**2
  sum1 += sum2 * k**3

print('Результат: %i\n' % sum1)
