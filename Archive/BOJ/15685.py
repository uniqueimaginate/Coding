import sys

input = sys.stdin.readline

N = int(input())
curves = [list(map(int, input().rstrip().split())) for _ in range(N)]
table = [[0] * 101 for _ in range(101)]

def move_direction(d, g):
    result = []
    directions = [d]
    for _ in range(g):
        size = len(directions)
        for i in range(size-1, -1, -1):
            directions.append((directions[i] + 1) % 4)
    return directions


def move_point(direction):
    global table, pos_x, pos_y
    table[pos_x][pos_y] = 1
    if direction == 0:
        pos_y = pos_y + 1
    elif direction == 1:
        pos_x = pos_x - 1
    elif direction == 2:
        pos_y = pos_y - 1
    elif direction == 3:
        pos_x = pos_x + 1
    table[pos_x][pos_y] = 1

def make_dragon_curve(d, g):
    directions = move_direction(d, g)
    # print(directions)
    for direction in directions:
        move_point(direction)
        
def check():
    global table
    count = 0
    for i in range(100):
        for j in range(100):
            if table[i][j] == 1 and table[i][j+1] == 1 and table[i+1][j] == 1 and table[i+1][j+1] == 1:
                count += 1
    return count

pos_x = pos_y = 0
for x, y, d, g in curves:
    pos_x, pos_y = y, x
    make_dragon_curve(d, g)
    
    
print(check())