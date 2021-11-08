def solution(absolutes, signs):
    answer = 0
    for i, num in enumerate(absolutes):
        sign = 1 if signs[i] else -1
        answer += (num * sign)
    
    return answer