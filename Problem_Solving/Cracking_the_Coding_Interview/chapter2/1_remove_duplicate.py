import random
from linked_list import LinkedListNode, LinkedList

class ListNode:
    def __init__(self, item, next=None):
        self.item = item
        self.next = next


def remove_duplicate_with_set(ll):
    head, prev = ll = None
    items = set()
    while head:
        if head.item in items:
            prev.next = head.next
        else:
            items.add(head.item)
            prev = head
        head = head.next


def remove_duplicate_with_repeat(ll):
    head, prev = ll, None

    while head:
        repeat = ll
        duplicate_flag = False
        while repeat:
            if repeat == head:
                break
            if repeat.item == head.item:
                duplicate_flag = True
                break
            repeat = repeat.next

        if duplicate_flag:
            prev.next = head.next
        else:
            prev = head
        head = head.next


# a = ListNode(0)
# head = a
# for i in range(10):
#     head.next = ListNode(random.randint(1, 9))
#     print(head.item, end='')

#     head = head.next

# remove_duplicate_with_repeat(a)

# print()

# head = a
# while head:
#     print(head.item, end='')
#     head = head.next
