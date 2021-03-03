# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    result: int = 0

    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:

        if root:
            if root.val in range(low, high+1):
                self.result += root.val

            if root.val > high:
                self.rangeSumBST(root.left, low, high)
            elif root.val < low:
                self.rangeSumBST(root.right, low, high)
            else:
                self.rangeSumBST(root.left, low, high)
                self.rangeSumBST(root.right, low, high)

        return self.result
