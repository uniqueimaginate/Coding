import copy
import sys
table = [list(map(int, input().split())) for _ in range(9)]

zeros = []
for i in range(9):
    for j in range(9):
        if table[i][j] == 0:
            zeros.append((i,j))
            

def check(x, y):
    numbers = {1,2,3,4,5,6,7,8,9}
    in_square = set()
    for i in range(3):
        for j in range(3):
            nx, ny = x // 3 * 3 + i,  y // 3 * 3 + j
            if table[x // 3 * 3 + i][y // 3 * 3 + j] != 0:
                in_square.add(table[nx][ny])
    
    minus1 = numbers - in_square
    
    in_square = set()
    # 같은 열 일 때
    for i in range(9):
        if table[i][y] != 0:
            in_square.add(table[i][y])
            
    minus2 = numbers - in_square

    
    in_square = set()
    # 같은 행 일 때
    for j in range(9):
        if table[x][j] != 0:
            in_square.add(table[x][j])
    
    minus3 = numbers - in_square

    return minus1 & minus2 & minus3
    
result = []
def dfs(z):
    if not z:
        for x,y in zeros:
            if len(check(x, y)) != 0:
                return
        for i in range(9):
            for j in range(9):
                print(table[i][j], end=" ")
            print()
        sys.exit(0)
        

    x, y = z[0][0], z[0][1]
    for num in check(x, y):
        table[x][y] = num
        dfs(z[1:])
        table[x][y] = 0
    
dfs(zeros)
