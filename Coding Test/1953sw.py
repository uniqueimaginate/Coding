from collections import deque

T = int(input())

N, M, R, C, L = 0, 0, 0, 0, 0
tunnel = []
visited = []
result = 0


def is_valid(x, y):
    global N, M
    if 0 <= x < N and 0 <= y < M:
        return True
    return False


def can_move(cur_x, cur_y, go_x, go_y, direction):
    global tunnel
    if direction == 0:
        if tunnel[go_x][go_y] in [1, 2, 5, 6]:
            return True
    elif direction == 1:
        if tunnel[go_x][go_y] in [1, 3, 6, 7]:
            return True
    elif direction == 2:
        if tunnel[go_x][go_y] in [1, 2, 4, 7]:
            return True
    elif direction == 3:
        if tunnel[go_x][go_y] in [1, 3, 4, 5]:
            return True
    return False


def count():
    global visited, L
    count = 0
    for i in range(N):
        for j in range(M):
            if 0 < visited[i][j] <= L:
                count += 1
    return count


def bfs():
    global N, M, R, C, L
    queue = deque([[R, C]])
    visited[R][C] = 1   
    cnt = 0
    while queue:
        x, y = queue.popleft()
        dirs = [
            [],
            [[-1, 0, 0], [0, 1, 1], [1, 0, 2], [0, -1, 3]],     # 위 -> 아래 <-
            [[-1, 0, 0], [1, 0, 2]],                            # 위 아래
            [[0, 1, 1], [0, -1, 3]],                            # -> <-
            [[-1, 0, 0], [0, 1, 1]],                            # 위 ->
            [[1, 0, 2], [0, 1, 1]],                             # 아래 ->
            [[1, 0, 2], [0, -1, 3]],                            # 아래 <-
            [[0, -1, 3], [-1, 0, 0]]                            # <- 위
        ]
        for direction in (dirs[tunnel[x][y]]):
            next_x, next_y = x + direction[0], y + direction[1]
            if is_valid(next_x, next_y) and can_move(x, y, next_x, next_y, direction[2]) and visited[next_x][next_y] == 0:
                    queue.append([next_x, next_y])
                    visited[next_x][next_y] = visited[x][y] + 1


for i in range(1, T+1):
    N, M, R, C, L = list(map(int, input().rstrip().split()))
    tunnel = [list(map(int, input().rstrip().split())) for _ in range(N)]
    visited = [[0] * M for _ in range(N)]
    bfs()
    print("#{} {}".format(i, count()))
