def solution(n, costs):
    root = [i for i in range(n + 1)]
    
    
    def find(x):
        if root[x] == x:
            return x
        else:
            root[x] = find(root[x])
            return root[x]
    
    def union(u, v):
        u = find(u)
        v = find(v)
        
        if u == v:
            return False
        
        root[u] = v
        return True
    
    costs.sort(key = lambda x : x[2])
    cnt = 0
    answer = 0
    for u, v, length in costs:
        if cnt == n - 1:
            break
        
        if union(u, v):
            answer += length
    
    
    return answer