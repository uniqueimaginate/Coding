import sys
import collections
input = sys.stdin.readline


N = int(input())
K = int(input())
apples = []
table = [[0] * N for _ in range(N)]
for i in range(K):
    x, y = list(map(int, input().split()))
    table[x-1][y-1] = 1
L = int(input())
turn = collections.deque()
for i in range(L):
    num, direction = input().split()
    turn.append((int(num), direction))

x = y = 0

# 0: right / 1: down / 2: left / 3: up
direction = 0
snake = collections.deque()
total_snake = set()

sec = 0
snake.append((x, y))
total_snake.add((x, y))

def move():
    global x, y, direction
    if direction == 0:
        y += 1
    elif direction == 1:
        x += 1
    elif direction == 2:
        y -= 1
    elif direction == 3:
        x -= 1
        
    if is_finished():
        return False
    else:
        check_apple()
        return True
    
def check_apple():
    global x, y, snake, total_snake
    if table[x][y] == 1:
        snake.appendleft((x,y))
        total_snake.add((x,y))
        table[x][y] = 0
    else:
        ix, iy = snake.pop()
        total_snake.remove((ix, iy))
        snake.appendleft((x, y))
        total_snake.add((x,y))

def check_turn():
    global sec, turn, direction

    if turn and turn[0][0] == sec:
        if turn[0][1] == 'L':
            if direction == 0:
                direction = 3
            else:
                direction -= 1
        else:
            direction = (direction + 1) % 4
        turn.popleft()
        

def is_finished():
    global x, y
    if x < 0 or y < 0 or x >= N or y >= N or (x,y) in total_snake:
        return True
    return False


while True:
    if not move():
        print(sec + 1)
        break
    
    sec += 1
    check_turn()
