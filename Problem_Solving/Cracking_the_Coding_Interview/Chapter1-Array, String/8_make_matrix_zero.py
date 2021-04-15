def make_matrix_zero(matrix):
    m = len(matrix)
    n = len(matrix[0])
    rows = set()
    cols = set()
    
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 0:
                rows.add(i)
                cols.add(j)
                
    for i in range(m):
        for j in range(n):
            if i in rows or j in cols:
                matrix[i][j] = 0
                
    return matrix


matrix = [[1,2,3],[4,0,6],[7,8,9]]

