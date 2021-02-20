import math
class Solution:
    def findComplement(self, num: int) -> int:
        divider = 2 ** int(math.log(num, 2) + 1) - 1
        return num ^ divider 
"""
https://leetcode.com/problems/number-complement/
XOR.
1111 ^ 1010 = 0101
"""