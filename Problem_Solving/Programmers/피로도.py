def solution(k, dungeons):
    max_cnt = 0
    def permutation(arr, cnt, kk, ele):
        nonlocal max_cnt
        max_cnt = max(cnt, max_cnt)    
    
        for i, num in enumerate(arr):
            if kk >= num[0]:
                temp = arr[:]
                temp.remove(arr[i])
                permutation(temp, cnt + 1, kk - num[1], ele)
    
    permutation(dungeons, 0, k, [])
    return max_cnt