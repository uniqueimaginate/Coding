from collections import Counter

def is_permutation_with_sort(string1, string2):
    return sorted(string1) == sorted(string2)


def is_permutation_with_counter(string1, string2):
    if len(string1) != len(string2):
        return False
    
    return Counter(string1) == Counter(string2)

