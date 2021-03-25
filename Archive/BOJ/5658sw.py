import sys
from collections import deque

def get_number(box):
    for i in range(0, len(box), time):
        ele = (''.join(box[i:i+time]))
        all_number.add(ele)

# input = sys.stdin.readline

T = int(input())

for i in range(T):
    N, K = list(map(int, input().rstrip().split()))
    box = deque(input().rstrip())
    time = len(box) // 4
    all_number = set()
    
    for _ in range(time):
        get_number(list(box))
        box.rotate(1)
    
    result = list(map(lambda x: eval('0x' + x), all_number))
    result.sort(reverse = True)
    print('#{} {}'.format(i+1, result[K-1]))




