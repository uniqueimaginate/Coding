from linked_list import LinkedListNode, LinkedList

def kth_element_from_back(ll, k):
    current = runner = ll.head
    for _ in range(k):
        if not runner:
            return None
        runner = runner.next
        
    while runner:
        runner = runner.next
        current = current.next
        
    return current