from collections import deque
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        q = deque()
        q.append("")
        ans = []
        while q:
            elem = q.popleft()
            if len(elem) == len(S):
                ans.append(elem)
            else:
                curIdx = len(elem)
                curChar = S[curIdx]
                if curChar.isalpha():
                    q.append(elem + curChar.lower())
                    q.append(elem + curChar.upper())
                else:
                    q.append(elem + curChar)
        return ans
"""
https://leetcode.com/problems/letter-case-permutation/
Subsets. BFS. 
"""