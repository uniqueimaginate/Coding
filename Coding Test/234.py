import re
import collections

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Using deque
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        d = collections.deque()
        curr_node = head
        while curr_node:
            d.append(curr_node.val)
            if(curr_node.next):
                curr_node = curr_node.next
            else:
                break

        while len(d) > 1:
            if d.popleft() != d.pop():
                return False

        return True

# Elegant
class Solution2:
    def isPalindrome(self, head: ListNode) -> bool:
        rev = None
        slow = fast = head

        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next

        while rev and rev.val == slow.val:
            slow, rev = slow.next, rev.next
        return not rev
