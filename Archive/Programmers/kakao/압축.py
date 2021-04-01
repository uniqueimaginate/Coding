def solution(msg):
    alphabet = '.ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    dic = {alpha: i for i, alpha in enumerate(alphabet)}
    
    num = 27
    pos = 0
    answer = []
    while pos < len(msg):
        i = 1
        while msg[pos:pos+i] in dic:            
            i += 1
            if pos + i >= len(msg) + 1  :
                break
            
        answer.append(dic[msg[pos:pos+i-1]])
        dic[msg[pos:pos+i]] = num
        num += 1
        pos = pos + i - 1
    
    
    return answer
