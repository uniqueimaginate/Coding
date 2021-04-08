import sys
INF = sys.maxsize
def solution(n, s, a, b, fares):
    def floyd_warshall():
        dist = [[INF] * n for _ in range(n)]
        
        for i in range(n):
            dist[i][i] = 0
        
        for x, y, fee in fares:
            dist[x-1][y-1] = fee
            dist[y-1][x-1] = fee

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
                    
        return dist
    
    dist = floyd_warshall()
    result = sys.maxsize
    
    for k in range(n):
        result = min(result, dist[s-1][k] + dist[k][a-1] + dist[k][b-1])
    

    return result