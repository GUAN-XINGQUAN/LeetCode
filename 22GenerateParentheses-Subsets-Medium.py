from collections import deque

class pStr:
    def __init__(self, string, openNum, closeNum):
        self.string = string
        self.openNum = openNum
        self.closeNum = closeNum

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        q = deque()
        q.append(pStr("", 0, 0))
        while q:
            elem = q.popleft()
            if elem.openNum == n and elem.closeNum == n:
                ans.append(elem.string)
            else:
                if elem.openNum < n:
                    q.append(pStr(elem.string + "(", elem.openNum + 1, elem.closeNum))
                if elem.openNum > elem.closeNum:
                    q.append(pStr(elem.string + ")", elem.openNum, elem.closeNum + 1))
        return ans
"""
https://leetcode.com/problems/generate-parentheses/
Subsets. BFS. 
"""