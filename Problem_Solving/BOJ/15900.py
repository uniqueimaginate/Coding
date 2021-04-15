import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
visited = [0] * 500001
cnt = 0


def dfs(graph, node, level):
    global cnt, visited
    is_leaf = True
    visited[node] = True

    for child in graph[node]:
        if not visited[child]:
            is_leaf = False
            dfs(graph, child, level + 1)

    if is_leaf:
        cnt += level


N = int(input().rstrip())
graph = [[] for _ in range(500001)]
for i in range(N-1):
    a, b = map(int, input().rstrip().split())
    graph[a].append(b)
    graph[b].append(a)

dfs(graph, 1, 0)

if cnt % 2:
    print("Yes")
else:
    print("No")
