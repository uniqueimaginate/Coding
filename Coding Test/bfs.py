graph = {
    1: [2, 3, 4],
    2: [5],
    3: [5],
    4: [],
    5: [6, 7],
    6: [],
    7: [3]
}


def bfs(v):
    discovered = [v]
    queue = [v]
    
    while queue:
        curr = queue.pop(0)
        for w in graph[curr]:
            if w not in discovered:
                queue.append(w)
                discovered.append(w)
    
    return discovered
    
    
    
    
print(bfs(1))

# [1, 2, 3, 4, 5, 6, 7]