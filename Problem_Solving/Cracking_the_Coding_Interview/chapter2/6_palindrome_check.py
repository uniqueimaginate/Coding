from linked_list import LinkedListNode, LinkedList


def is_palindrome_with_stack(ll):
    fast = slow = ll.head
    stack = []
    while fast and fast.next:
        stack.append(slow.val)
        fast = fast.next.next
        slow = slow.next

    if fast:
        slow = slow.next

    while slow:
        top = stack.pop()

        if slow.value != top:
            return False

        slow = slow.next

    return True


def is_palindrome(ll):
    slow = ll.head
    if not slow or not slow.next:
        return True

    fast = slow.next

    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next

    right_head = slow.next

    left, right = ll.head, reverse(right_head)
    result = True
    while left and right:
        if left.value != right.value:
            result = False
            break
        left = left.next
        right = right.next

    return result


def reverse(ll):
    prev, cur = None, ll
    while cur:
        next_node, cur.next = cur.next, prev
        prev, cur = cur, next_node

    return prev


ll = LinkedList([1, 2, 3, 4, 5, 4, 3, 2, 1])
print(is_palindrome(ll))
