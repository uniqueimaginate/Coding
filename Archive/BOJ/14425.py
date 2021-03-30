import sys

N, M = list(map(int, input().split()))
a = dict()
for i in range(N):
    string = input().rstrip()
    a[string] = 0
    
count = 0
for i in range(M):
    string = input().rstrip()
    if string in a:
        count += 1
        
print(count)