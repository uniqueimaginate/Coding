class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        a = [1]
        b = [1]
        res = []
        for i in range(len(nums) - 1):
            a.append(a[i] * nums[i])
            b.append(b[i] * nums[-i-1])

        b.reverse()

        for i in range(len(nums)):
            res.append(a[i] * b[i])

        return res


class Solution2:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        out = []
        p = 1

        for i in range(0, len(nums)):
            out.append(p)
            p = p * nums[i]
        p = 1

        for i in range(len(nums)-1, 0 - 1, -1):
            out[i] = out[i] * p
            p = p * nums[i]

        return out