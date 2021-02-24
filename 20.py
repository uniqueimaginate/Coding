class Solution:
    def isValid(self, s: str) -> bool:
        pair = {"(":")", ")":"(",
                "{":"}", "}":"{",
                "[":"]", "]":"["}
        
        opening = ['(', '{', '[']
        
        stck = []
        
        for char in s:
            if char in opening:
                stck.append(char)
            else:
                if not stck:
                    return False
                elif stck.pop() != pair[char]:
                    return False
            
        if stck:
                return False
        return True