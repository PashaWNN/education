"""
Шишмарев Павел. Вариант №14.
Задание 9. Задача 76е.
Поле шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит восьми: первое число — номер вертикали (при счете слева направо), второе — номер горизонтали (при счете снизу вверх). Даны натуральные числа k, l, m, n, каждое из которых не превосходит восьми. Требуется выяснить, можно ли с поля (k, l) одним ходом слона попасть на поле (m, n). Если нет, то выяснить, как это можно сделать за два хода (указать поле, на которое приводит первый ход).
"""


def color(x, y):
  if (x % 2) == 1:
    return (y % 2)
  else: return (1 if (y % 2 == 0) else 0)


def is_same_color(first, second):
  return color(first[0], first[1]) == color(second[0], second[1])


k = int(input("Введите k: "))
l = int(input("Введите l: "))
m = int(input("Введите m: "))
n = int(input("Введите n: "))

if (k > 8) or (k < 1) or (l > 8) or (l < 1) or (m > 8) or (m < 1) or (n > 8) or (n < 1):
  print("Неправильный ввод!")
else:
  if not(is_same_color((k,l),(m,n))):
    print("Клетки разных цветов, слон не может так ходить.")
  else:
    if (k, l) == (m, n):
      print("Слон уже находится в точке назначения.")
    else:
      if abs(k-m) == abs(l-n):
        print("Точка достижима за один ход")
      else:
        DeltaX = abs(k-m)
        DeltaY = abs(l-n)
        Delta = DeltaX + DeltaY
        if (m+Delta/2) <= 8:
          x = k + Delta/2
          y = l + Delta/2
        else:
          x = k + DeltaX - Delta/2
          y = l + DeltaX - Delta/2
          #Пока что работает не для всех случаев корректно, позже перепишу алгоритм.
        print("Промежуточная точка - (%d, %d)" % (x, y))
