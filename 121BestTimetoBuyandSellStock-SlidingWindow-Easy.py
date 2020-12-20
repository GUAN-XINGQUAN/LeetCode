class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        curWinMin = prices[0]
        sub = 0
        leftIdx = 0
        for rightIdx in range(len(prices)):
            if leftIdx == rightIdx:
                pass
            else:
                if prices[rightIdx] < curWinMin:
                    curWinMin = prices[rightIdx]
                    leftIdx = rightIdx
                else:
                    while prices[leftIdx] > curWinMin:
                        leftIdx += 1
                    sub = max(sub, -1 * (prices[leftIdx] - prices[rightIdx]))
        return sub
"""
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
Sliding window.
"""