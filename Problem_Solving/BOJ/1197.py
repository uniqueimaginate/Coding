import sys

input = sys.stdin.readline
V, E = map(int, input().rstrip().split())
root = [i for i in range(V+1)]
edges = []

def find(x):
    if root[x] == x:
        return x
    else:
        root[x] = find(root[x])
        return root[x]
        
def union(u, v):
    u = find(u)
    v = find(v)
    
    if u == v:
        return False
    
    root[u] = v
    return True

for _ in range(E):
    A, B, C = map(int, input().rstrip().split())
    edges.append((C, A, B))
    
edges.sort(key = lambda x: x[0])
result = 0

cnt = 0
for length, u, v in edges:
    if cnt == V - 1:
        break
    
    if union(u, v):
        result += length
        cnt += 1
        
print(result)