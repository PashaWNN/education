"""
Шишмарев Павел. Вариант №14.
Задание 24. Задача 338в.
Даны натуральное число n, целые числа a1,..., a25, b1,..., bn. Среди a1,..., a25 нет повторяющихся чисел, нет их и среди b1,..., bn.
Получить все члены последовательности b1,..., bn, которые не входят в последовательность a1,..., a25.
"""
n = -1
while n < 0:
  n = int(input('Введите натуральное число n: '))

a = []
b = []
d = []
for i in range(0, 25):
  while True:
    tmp = int(input('Введите a[%i]: ' % i))
    if not tmp in a:
      a.append(tmp)
      break
    else:
      print('Числа не должны повторяться!')

for i in range(0, n):
  while True:
    tmp = int(input('Введите b[%i]: ' % i))
    if not tmp in b:
      b.append(tmp)
      if not tmp in a:
        d.append(tmp)
      break
    else:
      print('Числа не должны повторяться!')

print('А: %s\n\nB: %s\n\nЧлены B, не входящие в A: %s' % (a, b, d))
