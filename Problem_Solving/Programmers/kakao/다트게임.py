import re

def solution(dartResult):
    answer = 0
    result = []
    cases = re.findall('\d+\w[*|#]?', dartResult)
    print(cases)
    for i, case in enumerate(cases):
        temp = list(case)
        num = 1
        flag = False
        for j, char in enumerate(temp):
            if char.isdigit() and char == '0' and flag:
                num = 10
                flag = False
            elif char.isdigit() and char == '1':
                flag = True
                num *= int(char)
            elif char.isdigit():
                num *= int(char)
            elif char.isalpha():
                flag = False
                if char == 'S':
                    num *= 1
                if char == 'D':
                    num = num ** 2
                elif char == 'T':
                    num = num ** 3
            else:
                flag = False
                if char == '*':
                    num *= 2
                    if i > 0:
                        result[i-1] = result[i-1] * 2
                elif char == '#':
                    num *= -1
                    
                        
        result.append(num)
    answer = sum(result)
    return answer