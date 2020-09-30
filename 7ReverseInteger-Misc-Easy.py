class Solution:
    def reverse(self, x: int) -> int:
        if x == 0 or x >= 2 ** 31 or x < -1 * 2 ** 31:
            return 0
        
        s = ""
        ans = ""
        ifNeg = False
        if x < 0:
            ifNeg = True
        s = str(x)
        if ifNeg:
            s = s[1:]
        
        for i in range(-1, -1 * len(s) - 1, -1):
            ans += s[i]
        
        ans = int(ans)
        if ifNeg:
            ans *= -1
            
        if ans >= 2 ** 31 or ans < -1 * 2 ** 31:
            return 0
        return ans
    
"""
https://leetcode.com/problems/reverse-integer/submissions/
"""