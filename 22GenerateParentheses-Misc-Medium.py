class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ansList = ["()"]
        if n == 1:
            return ansList
        for i in range(2, n + 1):
            curAnsList = set()
            for curAns in ansList:
                curLen = len(curAns)
                for loc in range(len(curAns) + 1):
                    part1 = curAns[:loc]
                    part2 = None
                    if loc == len(curAns):
                        part2 = ""
                    else:
                        part2 = curAns[loc:]
                    curAnsList.add(part1 + "()" + part2)
                    if loc == len(curAns):
                        break
                    for loc2 in range(loc + 1, len(curAns) + 1):
                        part2 = curAns[loc:loc2]
                        part3 = curAns[loc2:]
                        curAnsList.add(part1 + "(" + part2 + ")" + part3)
            ansList = curAnsList
        return list(ansList)
    
"""
https://leetcode.com/problems/generate-parentheses/submissions/
if curAnsList is set, then no dup.
Otherwise, "("s and ")"s may have order. This case is the same with the following quesiton - 
https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
"""