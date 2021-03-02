import re
import collections
import itertools

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        dic = collections.defaultdict(list)
                
        visited = set()
        traced = set()
        for x, y in prerequisites:
            dic[x].append(y)
            
        
        
        def dfs(i):
            if i in traced:
                return False
            if i in visited:
                return True
            
            traced.add(i)
            
            for y in dic[i]:
                if not dfs(y):
                    return False
            
            traced.remove(i)
            visited.add(i)
            
            return True
        
        for x in list(dic):
            if not dfs(x):
                return False
            
            
        return True