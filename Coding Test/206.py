# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, node = None, head
        while node:
            prev, prev.next, node = node, prev, node.next

        return prev


class Solution2:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, node = None, head
        while node:
            next, node.next = node.next, prev
            prev, node = node, next

        return prev
