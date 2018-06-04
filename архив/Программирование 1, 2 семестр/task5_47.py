"""
Шишмарев Павел. Вариант №14.
Задание 5. Задача 47.
Даны действительные числа x, y, z. 
Выяснить, существует ли треугольник с длинами сторон x, y, z. 
Если треугольник существует, то ответить - является ли он остроугольным
"""
def checkTriangle(a, b, c):
  result = {
             'exist': False,
             'acute': False,
           }
  if a + b > c and a + c > b and b + c > a:
    result['exist'] = True
  if ((a**2)+(b**2)-(c**2))/(2*a*b)<=0:
    result['acute'] = True
  return result

x = float(input("Введите X: "))
y = float(input("Введите Y: "))
z = float(input("Введите Z: "))
res = checkTriangle(x, y, z)
if res['exist']:
  print("Треугольник с заданными сторонами существует и %sявляется остроугольным!" % ('' if res['acute'] else 'не '))
else:
  print("Такой треугольник не существует!")

  
  
