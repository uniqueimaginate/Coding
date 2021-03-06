class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        current_sum = -2
        best_sum = nums[0]
        for i, num in enumerate(nums, 1):
            current_sum = max(current_sum + num, num)
            best_sum =  max(best_sum, current_sum)
            
        return best_sum