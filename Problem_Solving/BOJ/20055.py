import sys
N, K = list(map(int, input().split()))
A = list(map(int, sys.stdin.readline().rstrip().split()))
robot = [False] * 2 * N
up = 0
down = N - 1
count = 0

def rotate_belt():
    last_strong = A[-1]
    last_robot = robot[-1]
    for i in range(len(A)-1, 0, -1):
        A[i] = A[i-1]
        robot[i] = robot[i-1]
        
    A[0] = last_strong
    robot[0] = False
    robot[N] = False
    
def move_robot():
    robot[N] = False
    robot[N-1] = False
    flag = False
    for i in range(N-1, 0, -1):
        if robot[i] == False and A[i] > 0 and robot[i-1] == True:
            robot[i] = True
            robot[i-1] = False
            A[i] -= 1
            if i == 1:
                flag = True
    if flag:
        robot[0] = False
    
            
def up_robot():
    if robot[0] == False and A[0] > 0:
        robot[0] = True
        A[0] -= 1
        
def not_strong():
    global K
    count = 0
    for num in A:
        if num == 0:
            count += 1
    
    if count >= K:
        return True
    else:
        return False


while True:
    count += 1
    # print("rotate")
    rotate_belt()
    # print(A)
    # print(robot)
    # print("move")
    move_robot()
    # print(A)
    # print(robot)
    # print("up")
    up_robot()
    # print(A)
    # print(robot)
    if not_strong():
        break
    
print(count)