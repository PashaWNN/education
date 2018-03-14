"""
Шишмарев Павел. Вариант №14.
Задание 4. Задача 33в.
Даны действительные числа x, y. 
Получить max(x, y), min(x, y).
"""
x = float(input("Введите X: "))
y = float(input("Введите Y: "))

print("max(%d, %d) = %d" % (x, y, x if x > y else y))
print("min(%d, %d) = %d" % (x, y, x if x < y else y))

"""
Без использования тернарных операторов:
if x > y:
  _max, _min = x, y
else:
  _max, _min = y, x
print("max(%d, %d) = %d" % (x, y, _max))
print("min(%d, %d) = %d" % (x, y, _min))
"""
