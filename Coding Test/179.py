class Solution:
    def to_swap(self, num1, num2):
        return str(num1) + str(num2) < str(num2) + str(num1)
    
    
    def largestNumber(self, nums: List[int]) -> str:
        i = 1
        while i < len(nums):
            j = i
            while j > 0 and self.to_swap(nums[j-1], nums[j]):
                nums[j-1], nums[j] = nums[j], nums[j-1]
                j -= 1
            i += 1
            
        
        return str(int(''.join(map(str, nums))))