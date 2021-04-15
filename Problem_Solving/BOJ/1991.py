import collections

class TreeNode:
    def __init__(self, val = '', left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
        
        
tree = collections.defaultdict(TreeNode)

T = int(input())
for i in range(T):
    node, left, right = input().rstrip().split()
    tree[node].val = node
    if left != '.':
        tree[node].left = tree[left]
    if right != '.':
        tree[node].right = tree[right]
        
        
def preorder(node, ele):
    if not node:
        return
    
    ele.append(node.val)
    preorder(node.left, ele)
    preorder(node.right, ele)    
    
    return ele

def inorder(node, ele):
    if not node:
        return
    
    inorder(node.left, ele)
    ele.append(node.val)
    inorder(node.right, ele)
    
    return ele

def postorder(node, ele):
    if not node:
        return
    
    postorder(node.left, ele)
    postorder(node.right, ele)
    ele.append(node.val)
    
    return ele


print(''.join(preorder(tree['A'], [])))
print(''.join(inorder(tree['A'], [])))
print(''.join(postorder(tree['A'], [])))