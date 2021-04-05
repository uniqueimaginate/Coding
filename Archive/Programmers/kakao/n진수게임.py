def solution(n, t, m, p):
    def make_num(n, num):
        if num == 0:
            return "0"
        else:
            result = ""
            while num:
                if num % n < 10:
                    result += str(num % n)
                else:
                    i = (num % n) - 10
                    arr = ['A','B','C','D','E','F']
                    result += arr[i]
                num //= n
            result = result[::-1]
        return result    
    
    i = 0
    num_string = ""
    while True:
        if len(num_string) > t * m:
            break
        num_string += make_num(n, i)
        i += 1
    
    result = []
    for i in range(t):
        result.append(num_string[m * i + p - 1])
    answer = ''.join(result)
    return answer