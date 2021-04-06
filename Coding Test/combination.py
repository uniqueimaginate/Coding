result = []

def combination(arr, size, ele):
    if len(ele) == size:
        result.append(ele[:])
        return
    
    for i in range(len(arr)):
        ele.append(arr[i])
        combination(arr[i+1:], size, ele)
        ele.pop()
    

combination(range(9), 1, [])   # 1개 조합
combination(range(9), 2, [])   # 2개 조합
combination(range(9), 3, [])   # 3개 조합
combination(range(9), 4, [])   # 4개 조합
combination(range(9), 5, [])   # 5개 조합

print(result)