from linked_list import LinkedListNode, LinkedList

def discover_loop_with_set(ll):
    cur = ll.head
    alph = set()
    
    while cur:
        if cur.value in alph:
            return cur.value
        alph.add(cur.value)
        cur = cur.next
    
    return None
        
ll = LinkedList(['A','B','C','D','E','C'])


def discover_loop_with_runner(ll):
    fast = slow = ll.head

    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
        if fast is slow:
            break

    if fast is None or fast.next is None:
        return None

    slow = ll.head
    while fast is not slow:
        fast = fast.next
        slow = slow.next

    return fast


print(discover_loop_with_set(ll))