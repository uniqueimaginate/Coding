import sys
import collections
import copy


def get_empty_block():
    global lab
    global empty
    for i in range(row):
        for j in range(col):
            if lab[i][j] == 0:
                empty.append((i, j))


def get_wall_candidates(start, elements):
    global candidates

    if len(elements) == 3:
        candidates.append(elements[:])
        return

    for i in range(start, len(empty)):
        elements.append(empty[i])
        get_wall_candidates(i+1, elements)
        elements.pop()


def can_virus_move(i, j):
    global lab
    if 0 <= i < len(lab) and 0 <= j < len(lab[0]) and lab[i][j] == 0:
        return True
    return False


def spread_virus(lab):
    def bfs(i, j):
        Q = collections.deque()
        Q.append((i, j))
        visited[i][j] = 1

        while Q:
            dx = [-1, 1, 0, 0]
            dy = [0, 0, -1, 1]
            idx, idy = Q.popleft()

            for i in range(len(dx)):
                x, y = idx + dx[i], idy + dy[i]
                if can_virus_move(x, y) and visited[x][y] == 0:
                    Q.append((x, y))
                    lab_copy[x][y] = 2
                    visited[x][y] = 1

    lab_copy = copy.deepcopy(lab)
    visited = [[0] * len(lab[0]) for _ in range(len(lab))]
    for i in range(len(lab)):
        for j in range(len(lab[0])):
            if lab_copy[i][j] == 2 and visited[i][j] == 0:
                bfs(i, j)

    return count_zero(lab_copy)


def count_zero(lab):
    count = 0
    for i in range(len(lab)):
        for j in range(len(lab[0])):
            if lab[i][j] == 0:
                count += 1

    return count


input = sys.stdin.readline

row, col = list(map(int, input().split()))
lab = []

for i in range(row):
    lab.append(list(map(int, input().split())))

candidates = []
empty = []

get_empty_block()
get_wall_candidates(0, [])
max_num = -sys.maxsize

for candidate in candidates:
    for x, y in candidate:
        lab[x][y] = 1

    count = spread_virus(lab)
    max_num = max(count, max_num)

    for x, y in candidate:
        lab[x][y] = 0

print(max_num)

