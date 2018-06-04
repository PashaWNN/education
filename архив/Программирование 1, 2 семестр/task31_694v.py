n = -1
while n < 0:
    n = int(input('Введите n: '))

mtx = []
for i in range(0, n):
    mtx.append( ([0]*i) + [n-i] + ([0]*(n-i-1)) )

for i in mtx:
    res = ''
    for j in i:
        res += '%3s' % j
    print(res)
