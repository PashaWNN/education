"""
Шишмарев Павел. Вариант №14.
Задание 2. Задача 11ж.
Даны x, y, z. Вычислить a, b по приведённым формулам.
"""
from math import log, sqrt

def a(x, y, z):
  try:
    return log(abs(y-sqrt(abs(x))))*(x-y/(z+x**2/4))
  except ZeroDivisionError:
    print("Ошибка деления на ноль! Выражение z+x^2/4 равно нулю.")
  except ValueError:
    print("Ошибка: попытка взять логарифм от нуля. Выражение |sqrt(y-sqrt(|x|))| равно нулю.")

def _b(x):
    return x-(x**2/2*3)+(x**5/2*3*4*5)

x = float(input("Введите X: "))
y = float(input("Введите Y: "))
z = float(input("Введите Z: "))
try:
  print("A = {0:.2f}\nB = {1:.2f}".format(a(x,y,z), _b(x)))
except:
  pass
#Зачтено
