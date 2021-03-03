graph = {
    1: [2, 3, 4],
    2: [5],
    3: [5],
    4: [],
    5: [6, 7],
    6: [],
    7: [3]
}

discovered = []
def recursive_dfs_global(v):
    global discovered
    discovered.append(v)
    
    for next in graph[v]:
        if next not in discovered:
            discovered = recursive_dfs_global(next)
            
    return discovered

def recursive_dfs_local(v, discovered = []):
    discovered.append(v)
    
    for next in graph[v]:
        if next not in discovered:
            discovered = recursive_dfs_local(next, discovered)
            
    return discovered

def stack_dfs(start):
    stack = [start]
    discovered = []
    while stack:
        v = stack.pop()
        if v not in discovered:
            discovered.append(v)
            for next in graph[v]:
                stack.append(next)
            
    return discovered
        
    

print(recursive_dfs_local(1))
print(stack_dfs(1))


# [1, 2, 5, 6, 7, 3, 4]
# [1, 4, 3, 5, 7, 6, 2]