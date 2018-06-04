from lists import LinkedList as LL
from math import sqrt

def main():
    n = -1
    while n < 0:
        try:
            n = int(input('Введите n: '))
            if n < 0:
                raise ValueError
        except ValueError:
            print('Нужно вводить целое положительное число!')
    l = LL()
    result = 0

    for i in range(1, n+1):
        f = None
        while f is None:
            try:
                f = float(input(f'Введите x{i}: '))
            except ValueError:
                print('Нужно вводить число!')
        l.add(f)
    ch = l.first
    while ch.next is not None:
        result += sqrt(10 + ch.value**2)
        ch = ch.next

    print(f'Резульат: {result}')


if __name__ == '__main__':
    main()
