import re
import collections
import itertools
import heapq
import bisect

class Solution:
    dp = collections.defaultdict(int)
    dp[1] = 1
    dp[2] = 2
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        
        
        if self.dp[n]:
            return self.dp[n]
        
        
        self.dp[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
        
        return self.dp[n]
    
class Solution2:
    dp = collections.defaultdict(int)
    dp[1] = 1
    dp[2] = 2
    def climbStairs(self, n: int) -> int:
        for i in range(3, n+1):
            self.dp[i] = self.dp[i-1] + self.dp[i-2]
        
        return self.dp[n]