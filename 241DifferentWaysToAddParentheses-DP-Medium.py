class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        li = []
        leftIdx, rightIdx = 0, 0
        while rightIdx < len(input) + 1:
            if rightIdx == len(input):
                if leftIdx <= rightIdx:
                    li.append(int(input[leftIdx:rightIdx]))
                break
            
            curChar = input[rightIdx]
            if not input[rightIdx].isnumeric():
                if rightIdx == 0:
                    pass
                else:
                    li.append(int(input[leftIdx:rightIdx]))
                    li.append(curChar)
                    leftIdx = rightIdx + 1
            else:
                pass
            rightIdx += 1 
            
        dp = [[[] for _ in range(len(li))] for _ in range(len(li))]
        for i in range(len(li)):
            if type(li[i]) == int:
                dp[i][i].append(li[i])
        for step in range(len(li) + 1):
            for i in range(len(li) - step + 1): 
                for sepIdx in range(i + 1, i + step - 1):
                    curChar = li[sepIdx]
                    if type(curChar) == str:
                        ans1 = dp[i][sepIdx - 1]
                        ans2 = dp[sepIdx + 1][i + step - 1]
                        for ans_1 in ans1:
                            for ans_2 in ans2:                                
                                if curChar == "+":
                                    dp[i][i + step - 1].append(ans_1 + ans_2)
                                elif curChar == "-":
                                    dp[i][i + step - 1].append(ans_1 - ans_2)
                                elif curChar == "*":
                                    dp[i][i + step - 1].append(ans_1 * ans_2)
        return dp[0][len(li) - 1]
                            
"""
https://leetcode.com/problems/different-ways-to-add-parentheses/
DP. Note that there might be some numbers whose lenght is greater than 1, like 11.
As a result, we applied a sliding window solution first to parse the input string into a list,
e.g.[2, '*', 3, '-', 4, '*', 5]
""" 