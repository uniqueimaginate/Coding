def solution(key, lock):
    def rotate_matrix(rkey):
        return list(zip(*rkey[::-1]))
    
    def attach(x, y, rkey):
        for i in range(len(key)):
            for j in range(len(key)):
                extended_lock[x+i][y+j] += rkey[i][j]
    
    def detach(i, j, rkey):
        for i in range(len(key)):
            for j in range(len(key)):
                extended_lock[x+i][y+j] -= rkey[i][j]
    
    def check():
        for i in range(len(lock)):
            for j in range(len(lock)):
                if extended_lock[i+key_size][j+key_size] != 1:
                    return False
        return True
    
    
    key_size = len(key)
    size = len(lock) + 2 * key_size
    extended_lock = [[0] * size for _ in range(size)]
    
    for i in range(len(lock)):
        for j in range(len(lock)):
            extended_lock[i+key_size][j+key_size] = lock[i][j]
            
    for i in range(len(extended_lock) - key_size + 1):
        for j in range(len(extended_lock) - key_size + 1):
            rotated_key = key
            for k in range(4):
                rotated_key = rotate_matrix(rotated_key)
                attach(i, j, rotated_key)
                if check():
                    return True
                detach(i, j, rotated_key)
    
    return False