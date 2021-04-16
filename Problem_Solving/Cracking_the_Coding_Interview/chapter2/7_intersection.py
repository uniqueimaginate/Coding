from linked_list import LinkedListNode, LinkedList

def intersection(l1, l2):
    if l1.tail is not l2.tail:
        return False
    
    shorter = l1 if len(l1) < len(l2) else l2
    longer = l2 if len(l2) > len(l1) else l1
    
    diff = len(longer) - len(shorter)
    
    shorter_node, longer_node = shorter.head, longer.head
    
    for _ in range(diff):
        longer_node = longer_node.next
        
    while shorter_node is not longer_node:
        shorter_node = shorter_node.next
        longer_node = longer_node.next
        
    return longer_node