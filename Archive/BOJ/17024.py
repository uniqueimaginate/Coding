import sys
import collections


T = int(input())
tree = collections.defaultdict(list)
for _ in range(T-1):
    N, M = list(map(int, sys.stdin.readline().rstrip().split()))
    tree[N].append(M)
    tree[M].append(N)

print(len(max(tree.values(), key=len)) + 1)