import re
import collections
import itertools
import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return sorted(nums, reverse=True)[k-1]


class Solution2:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        heap = []

        for num in nums:
            heapq.heappush(heap, -num)

        for _ in range(k-1):
            heapq.heappop(heap)

        return -heapq.heappop(heap)


class Solution3:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        heapq.heapify(nums)

        for _ in range(len(nums) - k):
            heapq.heappop(nums)

        return heapq.heappop(nums)

class Solution4:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]