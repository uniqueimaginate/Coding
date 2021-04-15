import sys
import copy
import itertools
input = sys.stdin.readline
N, M = list(map(int, input().split()))
office = [list(map(int, input().split())) for _ in range(N)]

black_zone = sys.maxsize
cctvs = []
cctvs_rotate = []

def make_direction(x, y, direction, office):
    # 오른쪽
    if direction == 0:
        for j in range(y, M):
            if office[x][j] == 0:
                office[x][j] = '#'
            elif office[x][j] == 6:
                break
    # 위쪽
    elif direction == 1:
        for i in range(x, -1, -1):
            if office[i][y] == 0:
                office[i][y] = '#'
            elif office[i][y] == 6:
                break
    # 왼쪽
    elif direction == 2:
        for j in range(y, -1, -1):
            if office[x][j] == 0:
                office[x][j] = '#'
            elif office[x][j] == 6:
                break
    
    # 아래쪽
    elif direction == 3:
        for i in range(x, N):
            if office[i][y] == 0:
                office[i][y] = '#'
            elif office[i][y] == 6:
                break
            
def style2(x, y, direction, office):
    # 수평
    if direction == 0:
        make_direction(x, y, 0, office)
        make_direction(x, y, 2, office)
    # 수직
    elif direction == 1:
        make_direction(x, y, 1, office)
        make_direction(x, y, 3, office)
        
def style3(x, y, direction, office):
    if direction == 0:
        make_direction(x, y, 0, office)
        make_direction(x, y, 1, office)
    elif direction == 1:
        make_direction(x, y, 1, office)
        make_direction(x, y, 2, office)
    elif direction == 2:
        make_direction(x, y, 2, office)
        make_direction(x, y, 3, office)
    elif direction == 3:
        make_direction(x, y, 3, office)
        make_direction(x, y, 0, office)
        
def style4(x, y, direction, office):
    if direction == 0:
        make_direction(x, y, 0, office)
        make_direction(x, y, 1, office)
        make_direction(x, y, 2, office)
    elif direction == 1:
        make_direction(x, y, 1, office)
        make_direction(x, y, 2, office)
        make_direction(x, y, 3, office)
    elif direction == 2:
        make_direction(x, y, 2, office)
        make_direction(x, y, 3, office)
        make_direction(x, y, 0, office)
    elif direction == 3:
        make_direction(x, y, 3, office)
        make_direction(x, y, 0, office)
        make_direction(x, y, 1, office)

def style5(x, y, office):
    make_direction(x, y, 0, office)
    make_direction(x, y, 1, office)
    make_direction(x, y, 2, office)
    make_direction(x, y, 3, office)

        
def make_cctv_rotate(copy_cctvs, element):
    global cctvs, cctvs_rotate    
    if len(element) == len(cctvs):
        cctvs_rotate.append(element[:])
        return
    
    if copy_cctvs:
        _, _, case = copy_cctvs.pop(0)
        if case == 2:
            for num in [0,1]:
                element.append(num)
                make_cctv_rotate(copy_cctvs[:], element)
                element.pop()
        else:
            for num in [0,1,2,3]:
                element.append(num)
                make_cctv_rotate(copy_cctvs[:], element)
                element.pop()
                       
        
def count_result(office):
    count = 0
    for i in range(N):
        for j in range(M):
            if office[i][j] == 0:
                count += 1
    return count


def init():
    for i in range(N):
        for j in range(M):
            if office[i][j] != 0 and office[i][j] != 6:
                cctvs.append([i, j, office[i][j]])


init()
make_cctv_rotate(copy.deepcopy(cctvs), [])
# a = list(map(list, itertools.permutations([0,1,2,3], 4)))


a = list((itertools.product([0,1,2,3], repeat = len(cctvs))))
# print(a)

for directions in a:
    copy_office = copy.deepcopy(office)
    for i, val in enumerate(cctvs):
        x, y, case = val
        if case == 1:
            make_direction(x, y, directions[i], copy_office)
        elif case == 2:
            style2(x, y, directions[i], copy_office)
        elif case == 3:
            style3(x, y, directions[i], copy_office)
        elif case == 4:
            style4(x, y, directions[i], copy_office)
        elif case == 5:
            style5(x, y, copy_office)
    
    black_zone = min(count_result(copy_office), black_zone)


print(black_zone)