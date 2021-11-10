from collections import deque
def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 9876543210
    matrix = [[0 for _ in range(102)] for _ in range(102)]
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    def draw_rectangle(rec):
        nonlocal matrix
        for llx, lly, rhx, rhy in rec:
            lx, ly, rx, ry = 2 * llx, 2 * lly, 2 * rhx, 2 * rhy
            for i in range(lx, rx + 1):
                matrix[i][ly] = 1
                matrix[i][ry] = 1

            for j in range(ly, ry + 1):
                matrix[lx][j] = 1
                matrix[rx][j] = 1

    
    def is_valid(x, y, rec):
        nonlocal matrix
        if 0 < x < 102 and 0 < y < 102 and matrix[x][y] == 1 and is_outside(x, y, rec) :
            return True
        else:
            return False
    
    def is_outside(x, y, rec):
        nonlocal matrix
        # 먼저 내부인 경우 False 처리 한다.
        for llx, lly, rhx, rhy in rec:
            lx, ly, rx, ry = 2 * llx, 2 * lly, 2 * rhx, 2 * rhy
            if lx < x < rx and ly < y < ry:
                return False
        

        return True
    
        
    draw_rectangle(rectangle)
    
    q = deque()
    q.append([2 * characterX, 2 * characterY, 0])
    
    while q:
        x, y, cnt = q.popleft()
        matrix[x][y] = 0
        if x == 2 * itemX and y == 2 * itemY:
            return cnt / 2
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if is_valid(nx, ny, rectangle):
                q.append([nx, ny, cnt + 1])
                
    
    
    return answer