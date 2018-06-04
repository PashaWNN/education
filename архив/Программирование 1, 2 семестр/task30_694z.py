n = -1
while n < 0:
    n = int(input('Введите n: '))

mtx = []
m = 1 if (n % 2) == 0 else 0
for i in range(0, n//2):
    mtx.append(([0]*i)+([1]*(n-2*i))+([0]*i))
for i in range(n//2-m, -1, -1):
    mtx.append(([0] * i) + ([1] * (n - 2 * i)) + ([0] * i))

for i in mtx:
    print(i)
#Зачтено