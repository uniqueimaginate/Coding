import collections
import sys
T = int(input())
visited = set()
graph = collections.defaultdict(list)

for _ in range(T-1):
    a, b = list(map(int, sys.stdin.readline().rstrip().split()))
    graph[a].append(b)
    graph[b].append(a)
    
parent = {}

def bfs():
    q = collections.deque([1])
    
    while q:
        p = q.popleft()
        for child in graph[p]:
            if child not in visited:
                parent[child] = p
                visited.add(child)
                q.append(child)

    
bfs()
for i in range(2, T+1):
    print(parent[i])