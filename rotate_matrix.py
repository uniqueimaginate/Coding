import copy
matrix = [[1,2,3], [4,5,6],[7,8,9]]

col = len(matrix[0])
new_matrix = [[0] * col for x in matrix]

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        new_matrix[i][j] = matrix[col-j-1][i]
matrix = new_matrix[:]
        
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        new_matrix[i][j] = matrix[col-j-1][i]
        
        
print(new_matrix)