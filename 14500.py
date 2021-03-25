import sys
input = sys.stdin.readline

N, M = list(map(int, input().split()))
table = [list(map(int, input().split())) for _ in range(N)]
result_max = -sys.maxsize

def get_sum(element):
    global result_max
    temp = 0
    for x, y in element:
        if 0 <= x < N and 0 <= y < M:
            temp += table[x][y]
        else:
            return
    result_max = max(result_max, temp)


def check(i, j):
    for k in range(19):
        element = []
        if k == 0:
            element.extend([(i, j), (i, j+1), (i, j+2), (i, j+3)])
        elif k == 1:
            element.extend([(i, j), (i+1, j), (i+2, j), (i+3, j)])
        elif k == 2:
            element.extend([(i, j), (i, j+1), (i+1, j), (i+1, j+1)])
        elif k == 3:
            element.extend([(i, j), (i, j+1), (i-1, j+1), (i-2, j+1)])
        elif k == 4:
            element.extend([(i, j), (i, j-1), (i-1, j-1), (i-2, j-1)])
        elif k == 5:
            element.extend([(i, j), (i-1, j), (i-1, j+1), (i-1, j+2)])
        elif k == 6:
            element.extend([(i, j), (i+1, j), (i+1, j+1), (i+1, j+2)])
        elif k == 7:
            element.extend([(i, j), (i+1, j), (i+1, j-1), (i+1, j-2)])
        elif k == 8:
            element.extend([(i, j), (i-1, j), (i-1, j-1), (i-1, j-2)])
        elif k == 9:
            element.extend([(i, j), (i, j+1), (i+1, j+1), (i+2, j+1)])
        elif k == 10:
            element.extend([(i, j), (i, j-1), (i+1, j-1), (i+2, j-1)])
        elif k == 11:
            element.extend([(i, j), (i+1, j), (i+1, j+1), (i+2, j+1)])
        elif k == 12:
            element.extend([(i, j), (i, j-1), (i+1, j-1), (i+1, j-2)])
        elif k == 13:
            element.extend([(i, j), (i+1, j), (i+1, j-1), (i+2, j-1)])
        elif k == 14:
            element.extend([(i, j), (i, j+1), (i+1, j+1), (i+1, j+2)])
        elif k == 15:
            element.extend([(i, j), (i, j+1), (i, j-1), (i+1, j)])
        elif k == 16:
            element.extend([(i, j), (i-1, j), (i+1, j), (i, j-1)])
        elif k == 17:
            element.extend([(i, j), (i, j+1), (i, j-1), (i-1, j)])
        elif k == 18:
            element.extend([(i, j), (i, j+1), (i+1, j), (i-1, j)])
        get_sum(element)


for i in range(N):
    for j in range(M):
        check(i, j)
        
print(result_max)
