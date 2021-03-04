def bubble_sort(nums: list):
    for i in range(1, len(nums)):
        for j in range(0, len(nums)-1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                
arr = [9,8,7,6,5,4,3,2,1]
bubble_sort(arr)
print(arr)



# O(n^2)