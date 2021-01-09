class Solution:
    def isPalindrome(self, s: str) -> bool:
        ret = []
        for char in s:
            if char.isalnum():
                ret.append(char.lower())
                
        while len(ret) > 1:
            if ret.pop(0) != ret.pop():
                return False
        
        return True