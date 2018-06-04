from lists import CycledLinkedList as CLL


def main():
    n = -1
    while n < 0:
        try:
            n = int(input('Введите n: '))
            if n < 0:
                raise ValueError
        except ValueError:
            print('Нужно вводить целое положительное число!')
    m = -1
    while m < 0:
        try:
            m = int(input('Введите m: '))
            if m < 0:
                raise ValueError
        except ValueError:
            print('Нужно вводить целое положительное число!')

    l = CLL()

    for i in range(1, n+1):
        l.add(i)

    current = l.last

    while not current.prev == current.next:
        print(l)
        for i in range(m):
            current = current.next
        current.remove()

    print(current.value)


if __name__ == '__main__':
    main()
