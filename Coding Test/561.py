# normal
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        result = 0
        nums.sort()
        
        for i in range(0, len(nums)-1, 2):
            result += nums[i]
        
        return result
    
# Pythonic    
class Solution2:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])