"""
Шишмарев Павел. Вариант №14.
Задание 28. Задача 680б.
В данной действительности матрице размера n x m (n ≥ 3, m ≥ 3) поменять местами:
б) столбцы с номерами 3 и n-2
"""
while True:
  m = int(input('Введите m: '))
  if m >= 3:
    break

while True:
  n = int(input('Введите n: '))
  if (n >= 3):
    break

mat = []
for i in range(0, n):
  lst = []
  for j in range(0, m):
    lst.append(float(input('[%i, %i]=' % (i, j))))
  mat.append(lst)

res = []
for row in mat:
  lst = list(row)
  tmp = lst[2]
  lst[2] = lst[n-3]
  lst[n-3] = tmp
  res.append(lst)

print('Исходная матрица: ')
for row in mat:
  print(row)
print('Результирующая матрица: ')
for row in res:
  print(row)
