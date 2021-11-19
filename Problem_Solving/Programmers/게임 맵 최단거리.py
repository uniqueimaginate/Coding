from collections import deque
def solution(maps):
    answer = 0
    
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    n, m = len(maps), len(maps[0])
    
    q = deque()
    q.append((0,0,1))

    
    while q:
        x, y, l = q.popleft()
        
        
        if x == n-1 and y == m-1:
            return l
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1:
                q.append((nx, ny, l + 1))
                maps[nx][ny] = 0
    
    
    return -1