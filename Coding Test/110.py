# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# my solve
class Solution:
    diff : int = 0
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        
        def dfs(node: TreeNode) -> int:
            
            if not node:
                return 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            height = max(left, right)
            self.diff = max(self.diff, abs(left-right))
            
            return height + 1
        
        dfs(root)
        return True if self.diff < 2 else False
    
# another solve
class Solution2:
    def isBalanced(self, root: TreeNode) -> bool:
        def dfs(node: TreeNode) -> int:
            
            if not node:
                return 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            if left == -1 or right == -1 or abs(left-right) > 1:
                return -1
            
            return max(left, right) + 1
        
        return dfs(root) != -1