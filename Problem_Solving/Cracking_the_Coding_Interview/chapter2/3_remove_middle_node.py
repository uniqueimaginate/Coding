from linked_list import LinkedListNode, LinkedList

def remove_middle_node(ll):
    if len(ll) <= 2:
        return 
    runner = current = ll.head
    prev = None
    while runner and runner.next:
        runner = runner.next.next
        prev = current
        current = current.next
        
    prev.next = current.next
