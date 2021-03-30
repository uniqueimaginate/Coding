matrix = [[1,2,3], [4,5,6],[7,8,9]]

def rotate_matrix90(matrix):
    new_matrix = [[0] * len(matrix) for _ in range(len(matrix))]
    col = len(matrix[0])
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            new_matrix[i][j] = matrix[col-j-1][i]
    return new_matrix


def cool_rotate_matrix90(matrix):
    return list(zip(*matrix))


print(rotate_matrix90(matrix))
print(cool_rotate_matrix90(matrix[::-1]))