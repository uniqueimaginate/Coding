from collections import defaultdict

def solution(gems):
    
    unique = set(gems)
    left, right = 0,0
    gem_dict = defaultdict(int)
    gem_dict[gems[right]] = 1
    answer = [0, len(gems) - 1]

    while left < len(gems) and right < len(gems):
        if len(gem_dict) == len(unique):

            if right - left < answer[1] - answer[0]:
                answer = [left, right]
            
            if gem_dict[gems[left]] == 1:
                del gem_dict[gems[left]]
            else:
                gem_dict[gems[left]] -= 1
            left += 1
            
            
        else:
            right += 1
            if right == len(gems):
                break
                
            if gems[right] in gem_dict.keys(): 
                gem_dict[gems[right]] += 1 
            else: 
                gem_dict[gems[right]] = 1
        
    return [answer[0]+1, answer[1]+1]