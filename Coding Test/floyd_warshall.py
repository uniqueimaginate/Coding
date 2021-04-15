import sys

INF = sys.maxsize
n = 4
arr = [[0, 2, INF, 4],[2, 0, INF, 5],[3, INF, 0, INF],[INF, 2, 1, 0]]
def floyd_warshall():
    dist = [[INF for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            dist[i][j] = arr[i][j]
            
            
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    
