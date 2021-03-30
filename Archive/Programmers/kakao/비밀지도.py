def solution(n, arr1, arr2):
    new_arr1 = []
    new_arr2 = []
    
    for ele in arr1:
        new_arr1.append(list(bin(ele)[2:].zfill(n)))
    
    for ele in arr2:
        new_arr2.append(list(bin(ele)[2:].zfill(n)))
    
    
    result = []
    for i in range(n):
        result.append([])
        for j in range(n):
            if new_arr1[i][j] == '1' or new_arr2[i][j] == '1':
                result[i].append('#')
            else:
                result[i].append(' ')
    answer = []    
    for ele in result:
        answer.append(''.join(ele))
    return answer