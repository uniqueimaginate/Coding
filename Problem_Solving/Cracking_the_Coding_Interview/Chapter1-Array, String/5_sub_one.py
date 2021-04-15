def sub_one(s1, s2):
    if abs(len(s1) - len(s2)) > 1:
        return False
    
    if len(s1) == len(s2):
        i = diff = 0
        while i < len(s1):
            if s1[i] != s2[i]:
                diff += 1
            i += 1
        return diff <= 1
    else:
        small = big = None
        if len(s1) > len(s2):
            small, big = s2, s1
        else:
            small, big = s1, s2
        
        for i, char in enumerate(big):
            if char not in small:
                break
        
        return big[:i] + big[i+1:] == small
                    
        
        
print(sub_one("pales", "pale"))
