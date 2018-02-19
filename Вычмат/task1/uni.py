import re


def f(x):
    return 2*(x**3)-3*(x**2)-12*x-5


def f1(x):
    return 6*((x**2)-6*x-12)


def f2(x):
    return 12*x-6


epsilon = 0.001
a = -1.0
b = 1.0
_next = True
print("f(a)*f(b)=", f(a)*f(b))
if f(a)*f(b) < 0:
    while _next:
        if f(a)*f2(a) < 0:
            a = a - f(a)*((a-b)/(f(a)-f(b)))
        elif f(a)*f2(a) > 0:
            a = a - (f(a)/f1(a))
        if f(b)*f2(b) < 0:
            b = b - f(b)*((b-a)/(f(b)-f(a)))
        elif f(b)*f2(b) > 0:
            b = b - (f(b)/f1(b))
        #print(a)
        #print(b)
        if not (abs(a - b) > epsilon):
            _next = False
            x = (a + b)/2
else:
    return "f(a)f(b) >= 0, что неправильно."
print("Результат: %f" % (calculate()))
