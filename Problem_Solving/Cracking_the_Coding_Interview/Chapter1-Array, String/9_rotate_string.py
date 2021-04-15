def rotate_string(s1: str, s2: str):
    idx = s2.index(s1[0])
    result = s2[idx:] + s2[:idx]
    
    return result == s1
    
def cool_rotate_string(s1, s2):
    if len(s1) == len(s2):
        return s2 in s1 * 2
    return False
