def quick_sort(nums, lo, hi):
    
    def partition(lo, hi):
        pivot = nums[hi]
        left = lo

        for right in range(lo, hi):
            if nums[right] < pivot:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
        
        nums[left], nums[hi] = nums[hi], nums[left]
        return left
    
    if lo < hi:
        pivot = partition(lo, hi)
        quick_sort(nums, lo, pivot - 1)
        quick_sort(nums, pivot+1, hi)
        
        
a = [9,8,7,6,5,5,4,3,2,1]

quick_sort(a, 0, len(a)-1)
print(a)