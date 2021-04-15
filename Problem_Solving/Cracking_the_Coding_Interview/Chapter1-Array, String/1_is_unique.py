import collections

# 자료구조를 쓰는 방법
def is_unique_with_set(string):
    if len(set(string)) != len(string):
        return False
    else:
        return True
    
def is_unique_with_counter(string):
    counter = collections.Counter(string)
    max_num = counter.most_common(1)[0][1]
    
    if max_num > 1:
        return False
    else:
        return True
    
def is_unique_with_dict(string):
    words = dict()
    for c in string:
        if c in words:
            return False
        else:
            words[c] = 0
    return True

# 자료구조를 사용하지 않는 방법
def is_unique_with_bit_vector(string):
    # assume ASCII (128bit)
    if len(string) > 128:
        return False
    
    checker = 0
    for char in string:
        value = ord(char)
        if checker & (1 << value) != 0:
            return False
        checker |= (1 << value)
    
    return True
    

def is_unique_with_sorting(string):
    sorted_string = sorted(string)
    latest_char = None
    
    for char in string:
        if char == latest_char:
            return False
        latest_char = char
    return True