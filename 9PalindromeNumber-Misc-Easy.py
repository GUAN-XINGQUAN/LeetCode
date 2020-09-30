class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        if len(s) == 0 or len(s) == 1:
            return True
        
        for i in range(0, len(s) // 2):
            left = s[i]
            right = s[-1 - i]
            if left != right:
                return False
        return True

"""
https://leetcode.com/problems/palindrome-number/submissions/
"""