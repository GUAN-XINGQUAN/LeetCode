class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if len(triangle) == 0:
            return 0
        if len(triangle) == 1:
            return triangle[0][0]
        
        dp = []
        ans = 65536
        for i in range(len(triangle)):
            tmp = []
            for j in range(len(triangle[i])):
                if i == 0 and j == 0:
                    tmp.append(triangle[0][0])
                else:
                    curVal = triangle[i][j]
                    if j == 0:
                        tmp.append(curVal + dp[i - 1][j])
                    elif j == len(triangle[i]) - 1:
                        tmp.append(curVal + dp[i - 1][j - 1])
                    else:
                        tmp.append(curVal + min(dp[i - 1][j], dp[i - 1][j - 1]))
                if i == len(triangle) - 1:
                    ans = min(ans, tmp[-1])
            dp.append(tmp)
        return ans
"""
https://leetcode.com/problems/triangle/
DP. 
"""