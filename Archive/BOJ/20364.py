import sys

N, Q = list(map(int, input().split()))
visited = set()

def move(num):
    global visited
    point = num
    result = 0
    while num:
        if num in visited:
            result = num
        num //= 2
    
    if not result:
        visited.add(point)
    return result
    

for _ in range(Q):
    num = int(sys.stdin.readline().rstrip())
    print(move(num))
