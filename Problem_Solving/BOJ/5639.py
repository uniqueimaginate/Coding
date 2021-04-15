import sys
sys.setrecursionlimit(100000)

tree = []
try:
    while True:
        tree.append(int(input()))
except:
    pass        

def postorder(start, end):
    if start > end:
        return
    
    idx = end + 1
    
    
    for i in range(start+1, end+1):
        if tree[i] > tree[start]:
            idx = i
            break
        
    postorder(start+1, idx - 1)
    postorder(idx, end)    
    print(tree[start])


postorder(0, len(tree)-1)

