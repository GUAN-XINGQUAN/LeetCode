class Solution:
    def cal(self, number):
        s = 0
        while number > 0:
            s += (number % 10) ** 2
            number = number // 10 # IT'S PYTHON MY LORD! SHOULD BE "//"
        return s
    
    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        slow = n
        fast = self.cal(slow)
        if fast == 1:
            return True
        
        while fast != slow:
            slow = self.cal(slow)
            fast = self.cal(fast)
            if fast == 1:
                return True
            fast = self.cal(fast)
            if fast == 1:
                return True
        return False
"""
https://leetcode.com/problems/happy-number/
This question illustrate that there're often 2 ideas to sovle the "cycle" problmes 
1. hash
2. fast & slow pointers
"""