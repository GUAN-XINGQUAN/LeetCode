class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for rowIdx in range(len(A)):
            colIdx = 0
            while colIdx < len(A[0]) // 2:
                left = A[rowIdx][colIdx]
                right = A[rowIdx][-1 * colIdx - 1]
                A[rowIdx][colIdx] = right ^ 1
                A[rowIdx][-1 * colIdx - 1] = left ^ 1
                colIdx += 1
            if len(A[0]) % 2 == 1:
                A[rowIdx][colIdx] = A[rowIdx][colIdx] ^ 1
        return A
"""
https://leetcode.com/problems/flipping-an-image/
XOR. 
"""