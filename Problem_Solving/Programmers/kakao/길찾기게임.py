import sys
sys.setrecursionlimit(10000)
class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

def solution(nodeinfo):
    preorder_result = []
    posorder_result = []
    def preorder(node):
        if not node:
            return None
        
        preorder_result.append(node.val)
        preorder(node.left)
        preorder(node.right)
        return
        
    def posorder(node):
        if not node:
            return None
        
        posorder(node.left)
        posorder(node.right)
        posorder_result.append(node.val)
        return
    
    def make_tree(arr):
        if not arr:
            return None
        
        cur_x = arr[0][0]
        node = TreeNode(arr[0][2])
        left_tree = list(filter(lambda x : x[0] < cur_x, arr))
        right_tree = list(filter(lambda x : x[0] > cur_x, arr))
        node.left = make_tree(left_tree)
        node.right = make_tree(right_tree)
        return node
    
    nodes = []
    for i, node in enumerate(nodeinfo):
        
        nodes.append(node + [i+1])
    
    nodes.sort(key = lambda x : (-x[1], x[0]))
    root = make_tree(nodes)
    preorder(root)
    posorder(root)
    answer = []
    answer.append(preorder_result)
    answer.append(posorder_result)
    return answer