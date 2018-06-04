class Node:
    def __init__(self, value=None, next=None, prev=None, list=None):
        self.value = value
        self.next = next
        self.prev = prev
        self.list = list

    def __str__(self):
        return 'Node(%s)' % self.value

    def remove(self):
        self.prev.next = self.next
        self.next.prev = self.prev
        if self.list is not None:
            if self.list.last == self:
                self.list.last = self.prev
            elif self.list.first == self:
                self.list.first = self.next
        del self


class LinkedList:
    def __init__(self):
        self.first = None
        self.last = None

    def clear(self):
        self.__init__()

    def __str__(self):
        current = self.first
        res = 'LinkedList['
        while current.next is not None:
            res += str(current.value) + ', '
            current = current.next
        if current is not None:
            res += str(current.value)
        res += ']'
        return res

    def list(self):
        current = self.first
        while current.next is not None:
            yield current.value
            current = current.next
        yield current.value

    def add(self, value):
        if self.first is None:
            self.last = self.first = Node(value, None, None, self)
        else:
            n = Node(value, None, self.last, self)
            self.last.next = n
            self.last = n


class CycledLinkedList(LinkedList):
    def add(self, value):
        if self.first is None:
            self.last = self.first = Node(value, None, None, self)
            self.last.next = self.first
            self.last.prev = self.first
        else:
            n = Node(value, self.first, self.last, self)
            self.last.next = n
            self.last = n
            self.first.prev = n

    def __str__(self):
        current = self.first
        res = 'CycledLinkedList['
        while current != self.last:
            res += str(current.value) + ', '
            current = current.next
        if current is not None:
            res += str(current.value)
        res += ']'
        return res

