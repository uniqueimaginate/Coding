import collections

def solution(N, stages):
    stages_dic = collections.defaultdict(int)
    size = len(stages)
    for stage in stages:
        stages_dic[stage] += 1
    answer = []
    for i in range(1, N+1):
        if size == 0:
            answer.append((0, i))
        else:
            answer.append((stages_dic[i] / size, i))
        size -= stages_dic[i]
    
    answer.sort(key = lambda x : (-x[0], x[1]))
       
        
    return list(map(lambda x: x[1], answer))