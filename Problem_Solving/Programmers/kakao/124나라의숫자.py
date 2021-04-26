def solution(n):
    cases = ["4", "1", "2"]
    answer = ''

    while n:
        answer = cases[n % 3] + answer
        n = n // 3 - (n % 3 == 0)
    
    return answer