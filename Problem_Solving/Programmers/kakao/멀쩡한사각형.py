import math

# 이 풀이는 굉장히 불편한 풀이고, 문제의 핵심을 잡지 못했다.
def solution(w, h):
    empty = 0

    if w == h:
        return w * h - w
    elif w == 1 or h == 1:
        return 0

    for i in range(w):
        cur = h * i / w
        empty += int(cur)

    return empty * 2



def cool_solution(w, h):
    def gcd(a, b):
        while b != 0:
            r = a % b
            a = b
            b = r
        return a
    
    return w * h - w - h + gcd(w, h)