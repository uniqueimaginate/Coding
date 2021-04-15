T = int(input())
N = 0
table = []


def is_valid(x, y):
    global N
    if 0 <= x < N and 0 <= y < N:
        return True
    return False


def move(x, y, x_length, y_length):
    global N, table
    desert = set()
    cur_x, cur_y = x, y
    for i in range(x_length):
        nx, ny = cur_x - 1, cur_y + 1
        if is_valid(nx, ny) and table[nx][ny] not in desert:
            cur_x, cur_y = nx, ny
            desert.add(table[nx][ny])
        else:
            return False

    # 오른쪽 아래로 이동
    for i in range(y_length):
        nx, ny = cur_x + 1, cur_y + 1
        if is_valid(nx, ny) and table[nx][ny] not in desert:
            cur_x, cur_y = nx, ny
            desert.add(table[nx][ny])

        else:
            return False

    for i in range(x_length):
        nx, ny = cur_x + 1, cur_y - 1
        if is_valid(nx, ny) and table[nx][ny] not in desert:
            cur_x, cur_y = nx, ny
            desert.add(table[nx][ny])

        else:
            return False

    for i in range(y_length):
        nx, ny = cur_x - 1, cur_y - 1
        if is_valid(nx, ny) and table[nx][ny] not in desert:
            cur_x, cur_y = nx, ny
            desert.add(table[nx][ny])

        else:
            return False
    return True


def find_cafe(x, y):
    global N, table
    count = -1
    for x_length in range(1, N):
        for y_length in range(1, N):
            if move(x, y, x_length, y_length):
                count = max(count, 2 * (x_length + y_length))
    return count


for tc in range(1, T+1):
    N = int(input())
    table = [list(map(int, input().rstrip().split())) for _ in range(N)]
    count = -1
    for i in range(N):
        for j in range(N):
            count = max(find_cafe(i, j), count)
    print("#{} {}".format(tc, count))

