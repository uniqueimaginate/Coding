import re
import collections
import itertools
import heapq
import bisect
import sys

class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = collections.defaultdict(int)

        if not nums:
            return 0

        if len(nums) < 3:
            return max(nums)

        result = -sys.maxsize
        dp[0] = nums[0]
        dp[1] = nums[1]
        dp[2] = nums[2] + nums[0]


        for i in range(3, len(nums)):
            dp[i] = max(dp[i-2] + nums[i], dp[i-3] + nums[i])
            result = max(result, dp[i])

        result = max(result, dp[0], dp[1], dp[2])
        return result

class Solution2:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        if len(nums) <= 2:
            return max(nums)
        
        dp = collections.OrderedDict()
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
            
        return dp.popitem()[1]
        
    