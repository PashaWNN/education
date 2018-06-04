from lists import LinkedList


def main():
    n = -1
    while n < 0:
        try:
            n = int(input('Введите n: '))
            if n < 0:
                raise ValueError
        except ValueError:
            print('Нужно вводить целое положительное число!')

    l = LinkedList()
    fac_sum = 0
    cur_fac = 1
    for i in range(1, n+1):
        cur_fac *= i
        fac_sum += 1/cur_fac
        l.add(i * fac_sum)

    for i in l.list():
        print('%.2f' % i)


if __name__ == '__main__':
    main()