import sys

N = int(input())
table = [list(map(int, input().rstrip().split())) for _ in range(N)]


def floyd_warshall():
    dist = [[0] * N for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            dist[i][j] = table[i][j]


    for k in range(N):
        for i in range(N):
            for j in range(N):
                if dist[i][k] == 1 and dist[k][j] == 1:
                    dist[i][j] = 1
    
    for i in range(N):
        for j in range(N):
            print(dist[i][j], end=" ")
        print()

floyd_warshall()