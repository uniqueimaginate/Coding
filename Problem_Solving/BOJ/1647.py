import sys

input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
root = [i for i in range(N+1)]
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

for _ in range(M):
    A, B, C = map(int, input().rstrip().split())
    edges.append((A, B, C))
    
edges.sort(key = lambda x: x[2])

max_num = -1
cnt = 0
total = 0

for u, v, length in edges:
    if cnt == N-1:
        break
    
    if union(u, v):
        cnt += 1
        total += length
        max_num = max(max_num, length)
        
print(total - max_num)