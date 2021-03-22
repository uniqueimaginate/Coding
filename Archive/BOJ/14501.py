N = int(input())
DP = [0] * 16
arr = [[0,0]]
for i in range(N):
    arr.append(list(map(int, input().split())))
    

for i in range(1, N+1):
    for j in range(1, i+1):
        if j + arr[j][0] - 1 <= i:
            DP[i] = max(DP[i], DP[j-1] + arr[j][1])
            
              
print(DP[N])