def solution(routes):
    routes = sorted(routes, key = lambda x:x[0])
    answer = 1
    a = [routes[0]] 
    
    for start, end in routes[1:]:
        if (start <= a[answer-1][1]):
            a[answer-1] = [start, min(a[answer-1][1], end)]
        else: 
            answer += 1
            a.append([start, end])
    return answer   