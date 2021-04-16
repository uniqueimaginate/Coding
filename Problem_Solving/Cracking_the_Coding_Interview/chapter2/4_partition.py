from linked_list import LinkedListNode, LinkedList

def partition(ll, target):
    small = LinkedList()
    big = LinkedList()
    
    cur = ll.head
    
    while cur:
        if cur.value < target:
            small.add(cur.value)
        else:
            big.add(cur.value)
        cur = cur.next
            
    small.tail.next = big.head
    
    return small
