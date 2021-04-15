import collections

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

K = int(input())

wood = list(map(int, input().split()))

def make_tree(left, right):
    if left > right:
        return None
    mid = (left + right) // 2
    p = TreeNode(wood[mid])
    p.left = make_tree(left, mid - 1)
    p.right = make_tree(mid + 1, right)
    return p

def get_tree_level(tree):
    result = []
    level = 0
    root = tree
    q = collections.deque([root])
    result.append([root.val])
    while q:
        size = len(q)
        temp = []
        for _ in range(size):
            node = q.popleft()
            if node.left:
                temp.append(node.left.val)
                q.append(node.left)
            if node.right:
                temp.append(node.right.val)
                q.append(node.right)
        if temp:
            result.append(temp)
    return result
    

tree = make_tree(0, len(wood)-1)

result = get_tree_level(tree)

for level in result:
    print(*level)

