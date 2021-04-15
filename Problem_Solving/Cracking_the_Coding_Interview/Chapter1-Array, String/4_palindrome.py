from collections import Counter

def is_palindrome_permutation_pythonic(text):
    counter = Counter(text.replace(' ', '').lower())
    return sum(val % 2 for val in counter.values()) >= 1
    
def is_palindrom_permutation(text):
    lowered_text = text.lower()
    table = [0 for _ in range(26)]
    counter = 0
    for char in lowered_text:
        if char.isalpha():
            num = ord(char) - ord('a')
            table[num] += 1
            
            if table[num] % 2:
                counter += 1
            else:
                counter -= 1
        
    return counter <= 1
    
    