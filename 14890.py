import sys
input = sys.stdin.readline

N, L = list(map(int, input().split()))
table = [list(map(int, input().split())) for _ in range(N)]
visited = [[0] * N for _ in range(N)]
count = 0

def check_after_row(i, col, height):
    global L
    # 범위 확인
    if col + L - 1 >= N:
        return False

    # 모두가 같은 높이
    for l in range(L):
        if table[i][col + l] != height:
            return False

    # 다른 경사로 확인
    for l in range(L):
        if visited[i][col + l] == 1:
            return False

    for l in range(L):
        visited[i][col + l] = 1
    return True


def check_before_row(i, col, height):
    global L
    # 범위 확인
    if col - L < 0:
        return False

    # 모두가 같은 높이
    for l in range(1, L + 1):
        if table[i][col - l] != height:
            return False

    # 다른 경사로 확인
    for l in range(1, L + 1):
        if visited[i][col - l] == 1:
            return False

    for l in range(1, L + 1):
        visited[i][col - l] = 1
        
    return True


def check_after_column(i, row, height):
    global L
    # 범위 확인
    if row + L - 1 >= N:
        return False

    # 모두가 같은 높이
    for l in range(L):
        if table[row+l][i] != height:
            return False

    # 다른 경사로 확인
    for l in range(L):
        if visited[row+l][i] == 1:
            return False

    for l in range(L):
        visited[row+l][i] = 1
    return True


def check_before_column(i, row, height):
    global L
    # 범위 확인
    if row - L < 0:
        return False

    # 모두가 같은 높이
    for l in range(1, L + 1):
        if table[row-l][i] != height:
            return False

    # 다른 경사로 확인
    for l in range(1, L + 1):
        if visited[row-l][i] == 1:
            return False

    for l in range(1, L + 1):
        visited[row-l][i] = 1
        
    return True

# 행 조지기


def row():
    global count
    for i in range(N):
        col = 1
        can_cross = True
        while col < N:
            # 현재 칸이 이전 칸보다 1작을 때
            if table[i][col] + 1 == table[i][col-1]:
                if check_after_row(i, col, table[i][col]):
                    col += L
                    continue
                else:
                    can_cross = False
                    break

            # 현재 칸이 이전 칸보다 1클 때
            elif table[i][col] - 1 == table[i][col-1]:
                if check_before_row(i, col, table[i][col-1]):
                    col += 1
                    continue
                else:
                    can_cross = False
                    break

            # 현재 칸이 이전 칸이랑 같을 때
            elif table[i][col] == table[i][col-1]:
                col += 1
                continue
            # 이 외의 경우 = 전부다 못 건넘
            else:
                can_cross = False
                break
        if can_cross:
            count += 1


# 열 조지기
def col():
    global count
    for i in range(N):
        row = 1
        can_cross = True
        while row < N:
            # 현재 칸이 이전 칸보다 1작을 때
            if table[row][i] + 1 == table[row-1][i]:
                if check_after_column(i, row, table[row][i]):
                    row += L
                    continue
                else:
                    can_cross = False
                    break

            # 현재 칸이 이전 칸보다 1클 때
            elif table[row][i] - 1 == table[row-1][i]:
                if check_before_column(i, row, table[row-1][i]):
                    row += 1
                    continue
                else:
                    can_cross = False
                    break

            # 현재 칸이 이전 칸이랑 같을 때
            elif table[row][i] == table[row-1][i]:
                row += 1
                continue
            # 이 외의 경우 = 전부다 못 건넘
            else:
                can_cross = False
                break
        if can_cross:
            count += 1

row()
visited = [[0] * N for _ in range(N)]
col()
print(count)


