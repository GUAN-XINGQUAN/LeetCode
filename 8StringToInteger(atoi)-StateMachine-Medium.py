class Solution:
    def myAtoi(self, s: str) -> int:
        if len(s) < 1 or s == " ":
            return 0
        
        INITIAL = 0
        SIGN = 1
        VALUE = 2
        STOP = 3
        INVALID = 4
        sign = 1
        ans = []
        state = INITIAL
        idx = 0
        while state != INVALID and state != STOP and idx < len(s):
            char = s[idx]
            if state == INITIAL:
                if char == "-":
                    state = SIGN
                    sign = -1
                elif char == "+":
                    state = SIGN
                    sign = 1
                elif char == " ":
                    pass
                elif char.isdigit():
                    state = VALUE
                    ans.append(char)
                else:
                    state = INVALID                  
                    
            elif state == SIGN:
                if char.isdigit():
                    state = VALUE
                    ans.append(char)
                else:
                    state = INVALID
                    
            elif state == VALUE:
                if char.isdigit():
                    ans.append(char)
                else:
                    state = STOP
            idx += 1
        if state == INVALID or len(ans) == 0:
            return 0
        ansVal = int("".join(ans)) * sign
        if ansVal < -2 ** 31:
            ansVal = -2 ** 31
        elif ansVal > 2 ** 31 - 1:
            ansVal = 2 ** 31 - 1
        return ansVal
"""
https://leetcode.com/problems/string-to-integer-atoi/
State machine. Draw states before you code. 
"""