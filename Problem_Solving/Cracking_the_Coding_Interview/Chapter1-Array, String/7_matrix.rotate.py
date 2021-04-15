import copy

def cool_matrix_rotate90(matrix):
    return list(zip(*matrix))


def matrix_rotate90(matrix):
    new_matrix = [[0] * len(matrix[0]) for _ in range(len(matrix))]
    
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            new_matrix[i][j] = matrix[len(matrix) - 1 - j][i]
            
    return new_matrix
    
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

print(cool_matrix_rotate90(matrix[::-1]))
print(matrix_rotate90(matrix))