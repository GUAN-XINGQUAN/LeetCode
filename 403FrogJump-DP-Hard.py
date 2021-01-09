class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if len(stones) == 2:
            if stones[0] + 1 == stones[1]:
                return True
            else:
                return False
        mD = dict()
        for i in range(len(stones)):
            mD[stones[i]] = i
            
        dp = [[False for _ in range(len(stones))] for _ in range(len(stones))]
        dp[0][1] = True
        for startStoneIdx in range(1, len(stones)):
            startStone = stones[startStoneIdx]
            for endStoneIdx in range(startStoneIdx + 1, len(stones)):
                endStone = stones[endStoneIdx]
                lip = endStone - startStone
                for k in [lip, lip - 1, lip + 1]:
                    if k < 1:
                        continue
                    lastStone = startStone - k
                    if lastStone >= 0 and lastStone in mD and dp[mD[lastStone]][startStoneIdx]:
                        dp[startStoneIdx][endStoneIdx] = True
        for i in range(len(stones) - 1):
            if dp[i][len(stones) - 1]:
                return True
        return False
"""
https://leetcode.com/problems/frog-jump/
Very interesting DP problem. 
"""