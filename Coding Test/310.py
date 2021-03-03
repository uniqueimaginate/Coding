class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n <= 1:
            return [0]
        
        graph = collections.defaultdict(list)
        
        for i, j in edges:
            graph[i].append(j)
            graph[j].append(i)
            
        
        leaves = []
        
        for key in graph.keys():
            if len(graph[key]) == 1:
                leaves.append(key)
                
        
        
        while n > 2:
            n -= len(leaves)
            new_leaves = []
            for leaf in leaves:
                neighbor = graph[leaf].pop()
                graph[neighbor].remove(leaf)
                
                if len(graph[neighbor]) == 1:
                    new_leaves.append(neighbor)
                    
            leaves = new_leaves
            
        return leaves