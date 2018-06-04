from lists import LinkedList as LL


def main():
    n = -1
    while n < 0:
        try:
            n = int(input('Введите n: '))
            if n < 0:
                raise ValueError
        except ValueError:
            print('Нужно вводить целое положительное число!')
    if n < 2:
        print('Недостаточно значений для расчёта.')
        return
    l = LL()
    result = 1

    for i in range(1, n+1):
        f = None
        while f is None:
            try:
                f = float(input(f'Введите x{i}: '))
            except ValueError:
                print('Нужно вводить число!')
        l.add(f)
    ch = l.first.next
    ct = l.last
    while ch.next is not None:
        result *= ch.prev.value + ch.value + 2 * ct.value
        ch = ch.next
        ct = ct.prev

    print(f'Резульат: {result}')


if __name__ == '__main__':
    main()
