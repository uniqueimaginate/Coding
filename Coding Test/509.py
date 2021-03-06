import re
import collections
import itertools
import heapq
import bisect

class Solution:
    dp = collections.defaultdict(int)
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        
        
        if self.dp[n]:
            return self.dp[n]
        
        self.dp[n] = self.fib(n-1) + self.fib(n-2)
        
        return self.dp[n]
    
    
class Solution2:
    dp = collections.defaultdict(int)

    def fib(self, n: int) -> int:
        self.dp[1] = 1
        for i in range(2, n+1):
            self.dp[i] = self.dp[i-1] + self.dp[i-2]
        
        return self.dp[n]