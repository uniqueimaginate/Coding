def solution(s):
    answer = ''
    flag = False
    for char in s:
        if char.isalpha() and not flag:
            answer += char.upper()
            flag = True
        elif char == ' ':
            flag = False
            answer += char
        else:
            answer += char.lower()
            flag = True
    
    
    return answer