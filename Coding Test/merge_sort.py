def merge(left_nums, right_nums):
    result = []
    i, j = 0,0
    
    while i < len(left_nums) and j < len(right_nums):
        if left_nums[i] < right_nums[j]:
            result.append(left_nums[i])
            i += 1
        else:
            result.append(right_nums[j])
            j += 1
            
    while i < len(left_nums):
        result.append(left_nums[i])
        i += 1
        
    while j < len(right_nums):
        result.append(right_nums[i])
        j += 1
        
    return result
    
    

def merge_sort(nums):
    if len(nums) < 2:
        return nums[:] 
    else:
        mid = len(nums) // 2
        left = merge_sort(nums[:mid])
        right = merge_sort(nums[mid:])
        return merge(left, right)




a = [9,8,7,6,5,4,3,2,1]

b = merge_sort(a)

print(b)