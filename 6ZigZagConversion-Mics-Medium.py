class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s or numRows == 1:
            return s
        ans = ""
        idxInt = numRows * 2 - 2
        wInt = numRows - 2
        for row in range(0, numRows):
            for rnd in range(0, 1 + (len(s) - 1) // (numRows * 2 - 2)):
                # Vertical
                # Judge if vertical exist in current row.
                # 1. current vertical idx, suppose exists
                curVIdx = idxInt * rnd + row
                if curVIdx >= len(s):
                    break
                
                # 2. Vertical char exists. Add it into the output. 
                ans += s[curVIdx]
                # 3. If the first or last element in vertical, break
                if row == 0 or row == numRows - 1:
                    continue
                
                # Diagonal
                # Judge if diagonal exist in current row. 
                # 1. curVidx can be applied here firstly. 
                if curVIdx >= len(s):
                    break
                curDIdx = idxInt * rnd + numRows + (numRows - row - 2)
                if curDIdx >= len(s):
                    break
                ans += s[curDIdx]
        return ans

"""
https://leetcode.com/problems/zigzag-conversion/submissions/
"""