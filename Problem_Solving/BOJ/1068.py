from collections import defaultdict

N = int(input())
nodes = list(map(int, input().split()))
delete = int(input())


tree = defaultdict(list)
for i, node in enumerate(nodes):
    if node == delete or i == delete:
        continue
    tree[node].append(i)

check = 0   
def dfs(node):
    global check

    if node not in tree:
        check += 1
        return 
    
    for child in tree[node]:
        dfs(child)

if -1 not in tree:
    print("0")
else:
    dfs(-1)
    print(check)