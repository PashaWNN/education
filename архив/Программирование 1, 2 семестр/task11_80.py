"""
Шишмарев Павел. Вариант №14.
Задание 11. Задача 80.
Дано действительное число х, вычислить x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + x^13/13!
"""
x = float(input('Введите х: '))

lf = 2*3
res = x
for i in range(3, 14, 4):

  res -= (x**i / lf) 
  res += ( ( x**(i+2) ) / ( lf*(i+1)*(i+2) ) )
  lf *= (i+1) * (i+2) * (i+3) * (i+4)

print('Результат: {0:.8f}'.format(res))
#Зачтено
