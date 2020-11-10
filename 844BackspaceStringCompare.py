class Solution:        
    def cal(self, s):
        validIdx = None
        for wranglerIdx in range(len(s)):
            wChar = s[wranglerIdx]
            if wChar != "#":
                if validIdx != None:
                    validIdx += 1
                else:
                    validIdx = 0
                s[validIdx] = wChar
                
            else:
                if validIdx != None and validIdx > 0:
                    validIdx -= 1
                else:
                    validIdx = None
        return validIdx
    
    def backspaceCompare(self, S: str, T: str) -> bool:
        # Since the space complexity when using stacks is not O(1)
        # Let's try a 2 pointer method and solve in place. 
        # However, this method is not O(1) for space complexity actually, since string in python is immutable. 
        sList = list(S)
        tList = list(T)
        sv = self.cal(sList)
        tv = self.cal(tList)
        
        if sv != tv:
            return False
        if sv == None and tv == None:
            return True
        for idx in range(sv + 1):
            if sList[idx] != tList[idx]:
                return False
        return True

"""
https://leetcode.com/problems/backspace-string-compare/submissions/
2 Pointers
"""