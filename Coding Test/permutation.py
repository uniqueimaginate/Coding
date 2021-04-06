result = []
def permutation(arr, size, ele):
    
    if len(ele) == size:
        result.append(ele[:])
        return
    
    for i in range(len(arr)):
        ele.append(arr[i])
        temp = arr[:]
        temp.remove(arr[i])
        permutation(temp, size, ele)
        ele.pop()


permutation(range(9), 1, [])    # 1개 순열
permutation(range(9), 2, [])    # 2개 순열
permutation(range(9), 3, [])    # 3개 순열
permutation(range(9), 4, [])    # 4개 순열
permutation(range(9), 5, [])    # 5개 순열

print(result)