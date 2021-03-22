import sys

case = int(input())

for i in range(case):
    nums = list(map(int, sys.stdin.readline().rstrip().split()))
    average = (sum(nums[1:])/nums[0])
    total = list(filter(lambda x: x > average, nums[1:]))
    
    print("{:.3f}%".format(len(total) / nums[0] * 100))
    