class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates:
            return []
        
        def dfs(total, start):
            if total == target:
                result.append(temp_elements[:])
                return
            if total > target:
                return
            
            for i in range(start, len(candidates)):
                temp_elements.append(candidates[i])
                total += candidates[i]
                dfs(total, i)
                total -= candidates[i]
                temp_elements.pop()
                
                
        temp_elements = []
        result = []
        dfs(0, 0)
        
        return result
                