def solution(m, n, board):
    def get_target():
        flag = False
        for i in range(m-1):
            for j in range(n-1):
                if lb[i][j] != '0' and lb[i][j] == lb[i][j+1] and lb[i][j] == lb[i+1][j] and lb[i][j] == lb[i+1][j+1]:
                    checked[i][j] = checked[i][j+1] = checked[i+1][j] = checked[i+1][j+1] = -1
                    flag = True
        
        return flag
    
    def count_target():
        count = 0
        for i in range(m):
            for j in range(n):
                if checked[i][j] == -1:
                    count += 1
        return count
    
    def erase():
        for i in range(m):
            for j in range(n):
                if checked[i][j] == -1:
                    lb[i][j] = '-1'
        for j in range(n):
            count = 0
            alpha = []
            for i in range(m-1, -1, -1):
                if lb[i][j].isalpha():
                    count += 1
                    alpha.append(lb[i][j])
            
            for k in range(len(alpha)):
                lb[m-1-k][j] = alpha.pop(0)
                
            for k in range(m-1-count, -1, -1):
                lb[k][j] = '0'
                
    
    
    lb = []
    count = 0
    checked = []
    for b in board:
        lb.append(list(b))
    
    
    while True:
        checked = [[0] * n for _ in range(m)]
        if not get_target():
            return count
        
        count += count_target()
        erase()
