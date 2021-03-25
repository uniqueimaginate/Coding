import sys
input = sys.stdin.readline
N, M = list(map(int, input().split()))
r, c, direction = list(map(int, input().split()))
room = [list(map(int, input().split())) for _ in range(N)]


def is_backward_impossible():
    global direction, r, c
    if direction == 0:
        if room[r+1][c] == 1:
            return True
    elif direction == 1:
        if room[r][c-1] == 1:
            return True
    elif direction == 2:
        if room[r-1][c] == 1:
            return True
    elif direction == 3:
        if room[r][c+1] == 1:
            return True

    return False

def is_4way_impossible():
    global r, c
    all_4way = [(r, c+1), (r, c-1), (r+1, c), (r-1, c)]
    count = 0
    for x, y in all_4way:
        if room[x][y] == 1 or room[x][y] == 2:
            count += 1
    if count == 4:
        return True
    return False

def check_left():
    global direction, r, c
    left = []
    if direction == 0:
        direction = 3
        if room[r][c-1] == 0:
            c = c - 1
            return True
    elif direction == 1:
        direction = 0
        if room[r-1][c] == 0:
            r = r - 1
            return True
    elif direction == 2:
        direction = 1
        if room[r][c+1] == 0:
            c = c + 1
            return True
    elif direction == 3:
        direction = 2
        if room[r+1][c] == 0:
            r = r + 1
            return True
        
    return False
        
def count_cleaned_pos():
    count = 0
    for i in range(N):
        for j in range(M):
            if room[i][j] == 2:
                count += 1
                
    return count

def go_backward():
    global direction, r, c
    if direction == 0:
        r = r + 1
    elif direction == 1:
        c = c - 1
    elif direction == 2:
        r = r - 1
    elif direction == 3:
        c = c + 1

while True:
    room[r][c] = 2
    fin = False
    while True:
        if is_4way_impossible() and is_backward_impossible():
            fin = True
            break
        
        if is_4way_impossible() and not is_backward_impossible():
            go_backward()
            continue
        
        if check_left():
            break
        else:
            continue
        
    if fin:
        print(count_cleaned_pos())
        break