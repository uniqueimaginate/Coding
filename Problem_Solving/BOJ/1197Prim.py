import heapq
import sys
from collections import defaultdict

input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
heap = []
vertex = defaultdict(list)
visited = set()
for _ in range(M):
    a, b, c = map(int, input().rstrip().split())
    vertex[a].append((c, b))
    vertex[b].append((c, a))
    
visited.add(1)
for size, v in vertex[1]:
    heapq.heappush(heap, (size, v))
    
total = 0
while heap:
    size, v = heapq.heappop(heap)
    
    if v in visited:
        continue
    
    total += size
    visited.add(v)
    for new_size, new_v in vertex[v]:
        heapq.heappush(heap, (new_size, new_v))
        
print(total)
