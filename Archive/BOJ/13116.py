import sys
T = int(input())
def solution(A, B):
    while A != B:
        if A > B:
            A //= 2
        elif A < B:
            B //= 2
    print(A * 10)

for i in range(T):
    A, B = list(map(int, sys.stdin.readline().rstrip().split()))
    solution(A, B)


