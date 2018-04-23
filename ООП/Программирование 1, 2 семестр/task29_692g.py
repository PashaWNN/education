"""
Шишмарев Павел. Вариант №14.
Задание 29. Задача 692g.
Дана действительная квадратная матрица порядка n. Найти наибольшее из значений элементов, расположенных в заштрихованной части матрицы (рис. 39)
"""
while True:
  n = int(input('n: '))
  if n>0:
    break

mat = []
for i in range(0, n):
  lst = []
  for j in range(0, n):
    lst.append(float(input('[%i, %i]=' % (i, j))))
  mat.append(lst)

lst = []
for i in range(n//2, n):
  lst.append
