import sys

input = sys.stdin.readline

N, M, x, y, _ = list(map(int, input().split()))

dice_map = []

for i in range(N):
    dice_map.append(list(map(int, input().split())))
    
ops = list(map(int, input().split()))

dice = [0] * 6

def rotate(num):
    global dice
    def east():
        dice[0], dice[2], dice[3], dice[5] = dice[2], dice[5], dice[0], dice[3]
    
    def west():
        dice[0], dice[2], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[2]
    
    def north():
        dice[0], dice[1], dice[4], dice[5] = dice[1], dice[5], dice[0], dice[4]
    
    def south():
        dice[0], dice[1], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[1]
    
    if num == 1:
        east()
    elif num == 2:
        west()
    elif num == 3:
        north()
    elif num == 4:
        south()
        
def can_move(x, y):
    if 0 <= x < len(dice_map) and 0 <= y < len(dice_map[0]):
        return True
    return False

def check_bottom():
    global x
    global y
    global bottom
    if dice_map[x][y] == 0:
        dice_map[x][y] = dice[bottom]
    else:
        dice[bottom], dice_map[x][y] = dice_map[x][y], 0
    
    
bottom = 0
top = 5

for op in ops:
    move = [[0, 0], [0, 1], [0, -1], [-1, 0], [1, 0]]
    
    if can_move(x + move[op][0], y + move[op][1]):
        rotate(op)
        x += move[op][0]
        y += move[op][1]
        check_bottom()
        print(dice[top])
        
    else:
        continue
    