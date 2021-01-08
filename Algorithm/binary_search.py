import math

def binary_search(list, target):
    left = 0
    right = len(list) - 1
    
    while left < right:
        middle = math.floor((left + right) / 2)
        
        if target <= list[middle]:
            right = middle
        else:
            left = middle + 1
    
    if target == list[right]:
        return right
    return None
            

arr = [2, 4, 7, 12, 15, 21, 34, 34, 46, 57, 70, 82, 86, 92, 99]

print(binary_search(arr, 11))