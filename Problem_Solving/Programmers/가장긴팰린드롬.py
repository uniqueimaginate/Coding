def solution(s):
    answer = -1

    def expand(left, right):
        L, R = left, right
        while L >= 0 and R < len(s) and s[L] == s[R]:
            L -= 1
            R += 1
        
        return R - L - 1
    
    for i in range(len(s)):
        answer = max(answer, expand(i, i+1))
        answer = max(answer, expand(i, i))

    return answer