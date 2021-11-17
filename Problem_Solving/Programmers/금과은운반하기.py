def solution(a, b, g, s, w, t):
    answer = 10 ** 5 * 10 ** 9 * 2 * 2
    left = 0
    right = 10 ** 5 * 10 ** 9 * 2 * 2
    
    
    while left <= right:
        mid = (left + right) // 2
        gold = silver = total = 0
        
        for i in range(len(g)):
           
            mv, left = divmod(mid, t[i] * 2)
            
            if left >= t[i]:
                mv += 1
            
            
            gold += g[i] if g[i] < mv * w[i] else mv * w[i]
            silver += s[i] if s[i] < mv * w[i] else mv * w[i]
            total += g[i] + s[i] if (g[i] + s[i] < mv * w[i]) else mv * w[i]
        
        if gold >= a and silver >= b and total >= a + b:
            right = mid - 1
            answer = min(answer, mid)
        else:
            left = mid + 1
            
    return answer