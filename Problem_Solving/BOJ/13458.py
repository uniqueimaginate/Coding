import sys
test_zone = int(input())
people = list(map(int, sys.stdin.readline().rstrip().split()))
main, sub = list(map(int, input().split()))


count = 0
for person in people:
    count += 1
    temp = person - main
    if temp <= 0:
        continue
    else:
        carry, num = divmod(temp, sub)
        if num:
            count += (carry + 1)
        else:
            count += carry
            
print(count)