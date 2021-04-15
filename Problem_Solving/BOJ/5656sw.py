
from copy import deepcopy
from collections import deque   
T = int(input())


def count(table):
    global N, W, H
    count = 0
    for i in range(H):
        for j in range(W):
            if table[i][j] != 0:
                count += 1 
    return count


def is_valid(x, y):
    global N, W, H
    if 0 <= x < H and 0 <= y < W:
        return True
    return False

def go_down(table):
    global N, W, H
    for j in range(0, W):
        deq = deque()
        count = 0
        for i in range(H-1, -1, -1):
            if table[i][j] != 0:
                deq.append(table[i][j])
                table[i][j] = 0
                count += 1
        for i in range(count):
            table[H-1-i][j] = deq.popleft()

def blast_4_way(x, y, size, stack, table):
    global N, W, H
    for dist in range(1, size):
        if is_valid(x, y+dist) :
            stack.append([x, y+dist, table[x][y+dist]])
        if is_valid(x, y-dist) :
            stack.append([x, y-dist, table[x][y-dist]])
        if is_valid(x+dist, y) :
            stack.append([x+dist, y, table[x+dist][y]])
        if is_valid(x-dist, y) :
            stack.append([x-dist, y, table[x-dist][y]])

            
def blast(table, col):
    global N, W, H
    pos = 0
    for i in range(H):
        if table[i][col] != 0:
            pos = i
            break
    stack = [[pos, col, table[pos][col]]]
    
    while stack:
        x, y, size = stack.pop()
        if size == 0:
            continue
        elif size == 1:
            table[x][y] = 0
        else:
            table[x][y] = 0
            blast_4_way(x, y, size, stack, table)
            
def dfs(ele):
    global result, N, W, H, game_table
    if len(ele) == N:
        copy = deepcopy(game_table)
        for col in ele:
            blast(copy, col)
            go_down(copy)
        result = min(result,  count(copy))
    else:
        for i in range(W):
            if result == 0:
                break
            ele.append(i)
            dfs(ele)
            ele.pop()


result = 2000
N, W, H = 0, 0, 0
game_table = []
for i in range(T):
    N, W, H = list(map(int, input().rstrip().split()))
    game_table = [list(map(int, input().rstrip().split())) for _ in range(H)]
    result = 2000
    dfs([])
    print("#{} {}".format(i+1, result))