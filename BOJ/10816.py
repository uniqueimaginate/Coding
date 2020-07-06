num = int(input())
numlist1 = input().split()

numdict = {}

for i in numlist1:
    if i not in numdict:
        numdict[i] = 1
    else:
        numdict[i] += 1

num = int(input())
numlist2 = input().split()

for i in numlist2:
    if i in numdict:
        print(numdict[i], end=" ")
    else:
        print("0", end=" ")
    