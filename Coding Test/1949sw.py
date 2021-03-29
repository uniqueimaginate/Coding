T = int(input())

def get_peek():
    global mountain, N
    result = []
    peek_num = max([max(x) for x in mountain])
    for i in range(N):
        for j in range(N):
            if mountain[i][j] == peek_num:
                result.append((i, j))
    return result

def is_valid(x, y):
    if 0 <= x < N and 0 <= y < N:
        return True
    return False

def can_move(cur_x, cur_y, next_x, next_y):
    global mountain
    if mountain[cur_x][cur_y] > mountain[next_x][next_y]:
        return True
    return False


def dfs(cur_x, cur_y, length):
    global result, mountain
    dmove = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    for dx, dy in dmove:
        next_x, next_y = cur_x + dx, cur_y + dy
        if is_valid(next_x, next_y) and can_move(cur_x, cur_y, next_x, next_y):
            dfs(next_x, next_y, length + 1)
        else:
            result = max(result, length)

N = K = 0
mountain = []
mountain_peeks = []
result = 1

for t in range(T):
    N, K = list(map(int, input().rstrip().split()))
    mountain = [list(map(int, input().rstrip().split())) for _ in range(N)]
    mountain_peeks = get_peek()
    result = 1
    for peek_x, peek_y in mountain_peeks:
        for x in range(N):
            for y in range(N):
                for k in range(0, K+1):
                    mountain[x][y] -= k
                    dfs(peek_x, peek_y, 1)
                    mountain[x][y] += k
                        
    print("#{} {}".format(t+1, result))

