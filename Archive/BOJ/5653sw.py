T = int(input())
origin = 151
table_size = 352

N = M = K = 0
table = []
cells = []
active = []


def check():
    global table
    count = 0
    for i in range(table_size):
        for j in range(table_size):
            if table[i][j][1] != 0 and table[i][j][0] != -2:
                count += 1
    return count


def move_active():
    global table, active
    if not active:
        return
    else:
        active.sort(key=lambda x: -x[2])
        for i, j, case in active:
            dxy = [[0, 1], [0, -1], [1, 0], [-1, 0]]
            for dx, dy in dxy:
                new_x, new_y = i + dx, j + dy
                if table[new_x][new_y][0] == 0 and table[new_x][new_y][1] == 0:
                    table[new_x][new_y][1] = case
                    table[new_x][new_y][0] = -1
                    
        active = []


def set_active_inactive():
    global table, active
    move_active()

    for i in range(table_size):
        for j in range(table_size):
            if table[i][j][1] != 0 and table[i][j][0] != -2:
                table[i][j][0] += 1

                if table[i][j][0] == table[i][j][1]:
                    active.append((i, j, table[i][j][1]))
                if table[i][j][0] - table[i][j][1] >= table[i][j][1]:
                    table[i][j][0] = -2       
                       


for tc in range(1, T+1):
    N, M, K = list(map(int, input().rstrip().split()))
    table = [[[0 for depth in range(2)] for col in range(table_size) ] for row in range(table_size)]
    cells = [list(map(int, input().rstrip().split())) for _ in range(N)]
    active = []
    
    for i in range(N):
        for j in range(M):
            table[origin + i][origin + j][1] = cells[i][j]

    for i in range(K):
        set_active_inactive()
        
    print("#{} {}".format(tc, check()))
