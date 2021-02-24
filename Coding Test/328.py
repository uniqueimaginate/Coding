# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# My first Solution. looks bad
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        prev = head
        head = head.next
        first = prev
        second = head
        count = 0
        while head:
            count += 1
            if head.next:
                prev.next = head.next
                prev = head
                head = head.next
            else:
                prev.next = None
                break

        if count % 2 == 1:
            prev.next = second
        else:
            head.next = second

        return first


# My second Solution
class Solution2:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        
        odd = head
        even = head.next
        even_head = head.next
        
        while even and even.next:
            odd.next, even.next = odd.next.next, even.next.next
            odd, even = odd.next, even.next
        
        odd.next = even_head
        
        return head