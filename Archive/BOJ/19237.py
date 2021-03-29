import sys

input = sys.stdin.readline

N, M, k = list(map(int, input().split()))
shark_table = []
smell_table = []
direction_table = []
direction_priority_table = []
for i in range(N):
    shark_table.append(list(map(int, input().split())))
    smell_table.append([[0,0] for _ in range(N)])
    

direction_table.append(0)
direction_table.extend(list(map(int, input().split())))

for i in range(M):
    direction_priority_table.append([])
    direction_priority_table[i].append([])
    for j in range(4):
        direction_priority_table[i].append(list(map(int, input().split())))
        
sec = 0

def print_smell():
    global N, shark_table, smell_table
    for i in range(N):
        for j in range(N):
            if shark_table[i][j] != 0:
                shark_number = shark_table[i][j]
                smell_table[i][j][0] = shark_number
                smell_table[i][j][1] = k
                

def erase_smell():
    global N, shark_table, smell_table
    for i in range(N):
        for j in range(N):
            if shark_table[i][j] == 0:
                if smell_table[i][j][1] > 1:
                    smell_table[i][j][1] -= 1
                elif smell_table[i][j][1] == 1:
                    smell_table[i][j][0] = 0
                    smell_table[i][j][1] -= 1
            
def found_shark_only_one():
    global N, shark_table
    count = 0
    for i in range(N):
        for j in range(N):
            if shark_table[i][j] != 0 and shark_table[i][j] != 1:
                count += 1
                
    if count == 0:
        return True
    else:
        return False
    
def is_move_ok(i, j):
    if 0 <= i < N and 0 <= j < N:
        return True
    return False
    
    
def move(i, j, num):
    if num == 1:
        return (i - 1, j)
    elif num == 2:
        return (i + 1, j)
    elif num == 3:
        return (i, j - 1)
    elif num == 4:
        return (i, j + 1)
    
def shark_move(moving):
    global N, shark_table, smell_table, direction_table, direction_priority_table
    
    for i in range(N):
        for j in range(N):
            if shark_table[i][j] != 0:
                shark_number = shark_table[i][j]
                shark_direction = direction_table[shark_number]
                
                directions = direction_priority_table[shark_number-1][shark_direction]
                put_in_empty = False
                for num in directions:
                    x, y = move(i, j, num)
                    if is_move_ok(x, y):
                        if smell_table[x][y][0] == 0:
                            if shark_table[x][y] > shark_number or shark_table[x][y] == 0:
                                moving.append([x,y, shark_number])
                                direction_table[shark_number] = num
                                put_in_empty = True
                                break
                if not put_in_empty:
                    for num in directions:
                        x, y = move(i, j, num)
                        if is_move_ok(x, y):
                            if smell_table[x][y][0] == shark_number:
                                moving.append([x,y, shark_number])
                                direction_table[shark_number] = num
                                break
                # 이전 위치 제거
                shark_table[i][j] = 0
    
    

while True:
    if sec > 1000:
        print("-1")
        break
    if found_shark_only_one():
        print(sec)
        break
    
    moving = []
    print_smell()
    shark_move(moving)
    for x, y, shark_number in moving:
        if shark_table[x][y] == 0:
            shark_table[x][y] = shark_number
        elif shark_table[x][y] > shark_number:
            shark_table[x][y] = shark_number
            
    # print(shark_table)
    erase_smell()
    sec += 1    


