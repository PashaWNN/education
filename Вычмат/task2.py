eps1 = 0.001
eps2 = 0.01
delta  = 0.1
a = 0
b = 0
def fun(x):
    return 1.3**(2*x**2-3*x+1)


def fundx(x):
    return 1.3**(x*(-3 + 2*x))*(-1.02322 + 1.36429*x)


def dihotomy(a, b, f, fdx, e1, e2):
    while (abs(b-a)/2<=e1) and (fdx((b+a)/2)<e2):
        x = (a+b)/2
        f1 = f(x-e1)
        f2 = f(x+e1)
        if f1<f2:
            b = x
        else:
            a = x
    return (b+a)/2


def svenn(x0, d, f):
    if (f(x0-d)<=f(x0)) and (f(x0)>=f(x0+d)):
        print("Function isn't unimodal!")
        return False
    if (f(x0-d)>=f(x0)) and (f(x0+d)>=f(x0)):
        a = x0 - d
        b = x0 + d
        print("a = %f, b = %f" % (a, b))
        #return True
    if ((x0-d)>=f(x0)) and (f(x0)>=f(x0+d)):
        a = x0
        print("a = %f" % a)
    if (f(x0-d)<=f(x0)) and (f(x0)<=f(x0+d)):
        b = x0
        d = -d
        print("b = %f" % b)
    x1 = x0+d
    k = 1
    step = 0
    while True:
        step += 1
        x2  = x1+(k**2)*d
        fx0 = f(x0)
        fx1 = f(x1)
        fx2 = f(x2)
        print("Iteration #%d" % step)
        print("Point x=%f" % x2)
        print("f(x)=%f" % fx2)
        if d>0:
            a = x1
            print("a = %f" % a)
        if d<0:
            b = x1
            print("b = %f" % b)
        k += 1
        x0 = x1
        x1 = x2
        if ((fx0>=fx1) and (fx1<=fx2)):
            break
    if d>0: b = x2
    if d<0: a = x2
    return True
    

if svenn(0.8, delta, fun):
    r = dihotomy(a, b, fun, fundx, eps1, eps2)
    print('x = %f\nf(x) = %f' % (r, fun(r)))
