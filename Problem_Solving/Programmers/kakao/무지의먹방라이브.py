from collections import deque
import heapq

# 이 솔루션은 정확성만 통과한다.
def solution(food_times, k):
    deq = deque()
    total = 0
    for i, time in enumerate(food_times):
        deq.append([i+1, time])
        total += time
    
    if total <= k:
        return -1

    num = 0
    while True:
        if num == k:
            return (deq[0][0])
        if deq[0][1] > 0:
            deq[0][1] -= 1
            if deq[0][1] == 0:
                deq.popleft()
            else:
                deq.rotate(-1)
            num += 1

    answer = 0
    return answer



# 이 솔루션은 정확성과 효율성 모두 통과한다.
def solution(food_times, k):
    
    if sum(food_times) <= k:
        return -1
    
    heap = []
    for i, time in enumerate(food_times):
        heapq.heappush(heap, (time, i+1))
        
        
    sum_value = 0
    prev = 0
    length = len(food_times)
    
    while sum_value + ((heap[0][0] - prev) * length) <= k:
        cur = heapq.heappop(heap)[0]
        sum_value += ((cur - prev) * length)
        length -= 1
        prev = cur
        

    result = sorted(heap, key = lambda x: x[1])
    return result[(k - sum_value) % len(heap)][1]
    
    
