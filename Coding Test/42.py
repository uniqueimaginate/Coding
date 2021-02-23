# Stack
class Solution:
    def trap(self, height: List[int]) -> int:
        stck = []
        result = 0

        for i in range(len(height)):
            while stck and height[i] > height[stck[-1]]:

                top = stck.pop()

                if not len(stck):
                    break

                dist = i - stck[-1] - 1
                water = min(height[i], height[stck[-1]]) - height[top]

                result += dist * water

            stck.append(i)

        return result
    
# Two pointers
class Solution2:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        
        volume = 0
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]
        
        
        while left < right:
            left_max, right_max = max(height[left], left_max), max(height[right], right_max)
            
            if left_max <= right_max:
                volume += left_max - height[left]
                left += 1
            else:
                volume += right_max - height[right]
                right -= 1
        return volume
            