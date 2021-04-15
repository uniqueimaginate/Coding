import sys

def solution(n, times):
    def binary_search(left, right)->int:
        result = sys.maxsize
        while left <= right:
            mid = (left + right) // 2
            
            temp_time = 0
            for time in times:
                temp_time += (mid // time)
    
            if temp_time >= n:
                result = min(result, mid)
                right = mid-1
            elif temp_time < n:
                left = mid+1
        return result
    
    times.sort()
    start = n * times[0]
    result = binary_search(0, start)
    return result