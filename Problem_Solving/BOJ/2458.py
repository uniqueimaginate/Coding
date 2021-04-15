N, M = map(int, input().rstrip().split())
table = [[0] * (N+1) for _ in range(N+1)]
for _ in range(M):
    start, end = map(int, input().rstrip().split())
    table[start][end] = 1
    
    
def floyd_warshall():

    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if table[i][k] == 1 and table[k][j] == 1:
                    table[i][j] = 1

    result = [0] * (N+1)
    for i in range(1, N+1):
        for j in range(1, N+1):
            if table[i][j] == 1:
                result[i] += 1
                result[j] += 1
            
    print(result.count(N-1))
    
floyd_warshall()