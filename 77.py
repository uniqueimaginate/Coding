import re
import collections
import itertools

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        
        
        
        def dfs(start, elements):
            if k == len(elements):
                result.append(elements[:])
                
            for i in range(start, n+1):
                elements.append(i)
                dfs(i+1, elements)
                elements.pop()
                
                
        elements = []
        dfs(1, elements)
        
        return result
    
class Solution2:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(itertools.combinations(range(1, n+1), k))