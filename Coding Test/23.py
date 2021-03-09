import re
import collections
import itertools
import heapq
import bisect
import sys
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap = []
        root = result = ListNode(None)
        
        for i, list in enumerate(lists):
            if list:
                heapq.heappush(heap, (list.val, i, list))
                
        while heap:
            node = heapq.heappop(heap)
            
            idx = node[1]
            result.next = node[2]
            
            result = result.next
            
            if result.next:
                heapq.heappush(heap, (result.next.val, idx, result.next))
                
    
        return root.next