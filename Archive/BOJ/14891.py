import sys
input = sys.stdin.readline



topnis = [list(map(int, input().rstrip())) for _ in range(4)]
K = int(input())
rotate = [list(map(int, input().split())) for _ in range(K)]

def calculate():
    global topnis
    score = 0
    if topnis[0][0] == 1:
        score += 1
    if topnis[1][0] == 1:
        score += 2
    if topnis[2][0] == 1:
        score += 4
    if topnis[3][0] == 1:
        score += 8
    
    print(score)
        
def rotate_clockwise(topni):
    temp = topni[7]
    for i in range(7, 0, -1):
        topni[i] = topni[i-1]
    topni[0] = temp
    
def rotate_anticlockwise(topni):
    temp = topni[0]
    for i in range(0, 7):
        topni[i] = topni[i+1]
    topni[7] = temp




def rotate_topnis(num, direction):
    stack = [(num, direction, 0)]
    
    while stack:
        position, now_direction, way = stack.pop(0)
        
        if position + 1 < 5 and topnis[position-1][2] != topnis[position][6] and (way == 0 or way == 1):
            stack.append((position + 1, -now_direction, 1))
        if position - 1 > 0 and topnis[position-2][2] != topnis[position-1][6] and (way == 0 or way == -1):
            stack.append((position - 1, -now_direction, -1))
            
        if now_direction == 1:
            rotate_clockwise(topnis[position-1])
        else:
            rotate_anticlockwise(topnis[position-1])
    

for num, direction in rotate:
    rotate_topnis(num, direction)


calculate()
