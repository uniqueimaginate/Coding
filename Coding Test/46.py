import re
import collections
import itertools

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        
        
        def dfs(elements):
            if len(elements) == 0:
                result.append(prev_elements[:])
            
            
            for e in elements:
                next_elements = elements[:]
                next_elements.remove(e)
                
                prev_elements.append(e)
                dfs(next_elements)
                prev_elements.pop()
        
        
        result = []
        prev_elements = []
        dfs(nums)
        return result
    
    
class Solution2:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums))