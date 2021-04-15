import sys
input = sys.stdin.readline

def isValid(i, j):
    if 0 <= i < len(room) and 0 <= j < len(room[0]) and room[i][j] != -1:
        return True
    else:
        return False
    
def expand():
    dx = [1,-1, 0, 0]
    dy = [0, 0, -1, 1]
    for i in range(len(room)):
        for j in range(len(room[0])):
            if room[i][j] != -1 and room[i][j] != 0:
                l = 0
                for k in range(len(dx)):
                    x, y = i + dx[k], j + dy[k]
                    if isValid(x,y):
                        another_room[x][y] += (room[i][j] // 5)
                        l += 1
                    
                room[i][j] -= ((room[i][j] // 5) * l)
                        
    
    for i in range(len(room)):
        for j in range(len(room[0])):
            room[i][j] += another_room[i][j]
            another_room[i][j] = 0

def find_circulator():
    for i in range(len(room)):
        if room[i][0] == -1:
            return i

def circulate_clockwise():
    for i in range(circu_up, 0, -1):
        room[i][0] = room[i-1][0]
    room[circu_up][0] = -1
    
    for i in range(0, len(room[0])-1):
        room[0][i] = room[0][i+1]
    
    
    for i in range(0, circu_up):
        room[i][len(room[0])-1] = room[i+1][len(room[0])-1]
        
    for i in range(len(room[0]) - 1, 1, -1):
        room[circu_up][i] = room[circu_up][i-1]
    room[circu_up][1] = 0
        

def circulate_anticlockwise():
    for i in range(circu_down, len(room)-1):
        room[i][0] = room[i+1][0]
    room[circu_down][0] = -1
    
    for i in range(0, len(room[0])-1):
        room[len(room)-1][i] = room[len(room)-1][i+1]
        
    for i in range(len(room)-1, circu_down, -1):
        room[i][len(room[0])-1] = room[i-1][len(room[0])-1]
        
    for i in range(len(room[0])-1, 1, -1):
        room[circu_down][i] = room[circu_down][i-1]
        
    room[circu_down][1] = 0


def calculate_dust():
    count = 0
    for i in range(len(room)):
        for j in range(len(room[0])):
            if room[i][j] != -1:
                count += room[i][j]
                
    return count

def circulate():
    circulate_clockwise()
    circulate_anticlockwise()


R, C, T = list(map(int, input().split()))
room = []
another_room = []

for i in range(R):
    room.append(list(map(int, input().split())))
    another_room.append([0] * len(room[0]))
    
circulator_pos = find_circulator()
circu_up = circulator_pos
circu_down = circulator_pos + 1


while T:
    expand()
    circulate()
    T -= 1
    
print(calculate_dust())
    
