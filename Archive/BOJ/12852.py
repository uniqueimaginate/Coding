from collections import deque

N = int(input())

prev = [-1 for _ in range(N+1)]
cnt  = [-1 for _ in range(N+1)]

cnt[1] = 0
q = deque()
q.append([1, 0])
while q:
    prev_pos, prev_cnt = q.popleft()
    prev3 = prev_pos * 3
    prev2 = prev_pos * 2
    prev1 = prev_pos + 1
    
    if prev3 <= N and cnt[prev3] == -1:
        prev[prev3] = prev_pos
        cnt[prev3] = prev_cnt + 1
        q.append([prev3, prev_cnt + 1])

    if prev2 <= N and cnt[prev2] == -1:
        prev[prev2] = prev_pos
        cnt[prev2] = prev_cnt + 1
        q.append([prev2, prev_cnt + 1])

    if prev1 <= N and cnt[prev1] == -1:
        prev[prev1] = prev_pos
        cnt[prev1] = prev_cnt + 1
        q.append([prev1, prev_cnt + 1])
    
result = []
num = N
while num != 1:
    result.append(num)
    num = prev[num]
    
result.append(1)
print(cnt[N])
print(*result)