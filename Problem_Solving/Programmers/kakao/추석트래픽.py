import datetime
import sys


def to_seconds(x):
    h, m, s = x.split(":")
    total_seconds = float(h) * 3600 + float(m) * 60 + float(s)
    return total_seconds
    

def func(x):
    result = x.split()[1:]
    start = to_seconds(result[0]) - float(result[1][:-1]) + 0.001
    end = to_seconds(result[0])
    return (start, end)

def solution(lines):
    lines.sort()
    times = list(map(lambda x: func(x), lines))
    
    answer = 0

    for i, time1 in enumerate(times):
        start, end = time1[0], time1[1]
        
        cnt = 0
        for j in range(i, len(times)):
            if (start + 1 >= times[j][0]) or (end + 1 > times[j][0]):
                cnt += 1
                
        answer = max(answer, cnt)
    
    
    return answer
