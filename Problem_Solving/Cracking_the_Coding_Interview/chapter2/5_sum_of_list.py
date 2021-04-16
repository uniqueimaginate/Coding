from linked_list import LinkedListNode, LinkedList

def sum_of_list(ll1, ll2):
    cur1, cur2 = ll1.head, ll2.head
    carry = 0
    ll = LinkedList()
    
    while cur1 or cur2:
        total = 0
        if cur1:
            total += cur1.value
            cur1 = cur1.next
            
        if cur2:
            total += cur2.value
            cur2 = cur2.next
    
        carry, val = divmod(total+carry, 10)
        
        ll.add(val)
    
    if carry:
        ll.add(carry)
        
    return ll
    

