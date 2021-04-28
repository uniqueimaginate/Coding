import math
def solution(distance, rocks, n):
    rocks.append(distance)
    rocks.sort()
    
    left, right = 0, distance
    answer = 0

    while left <= right:
        prev = 0
        mins = math.inf
        mid = (left + right) // 2
        cnt = 0
        
        for i in range(len(rocks)):
            if rocks[i] - prev < mid:
                cnt += 1
            else:
                mins = min(mins, rocks[i] - prev)
                prev = rocks[i]
                
        if cnt > n:
            right = mid - 1
        else:
            answer = mins
            left = mid + 1        
    
    return answer