# Definition for a binary tree node.
import re
import collections
import itertools
import heapq

#  class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        q = collections.deque([root])
        depth = 0
        while q:
            depth += 1

            for _ in range(len(q)):
                cur_root = q.popleft()
                if cur_root.left:
                    q.append(cur_root.left)
                    
                if cur_root.right:
                    q.append(cur_root.right)
            
            
            
        return depth
            