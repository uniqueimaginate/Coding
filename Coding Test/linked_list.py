class ListNode:
    def __init__(self, item, next = None):
        self.item = item
        self.next = next


head = ListNode(0)
head.next = ListNode(1)
head.next.next = ListNode(2)

while head:
    print(head.item)
    head = head.next