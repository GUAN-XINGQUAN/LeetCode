class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount < 0:
            return -1
        
        sol = [0, ]
        max_amount = amount + 1
        for _a in range(1, amount + 1):
            sol.append(max_amount) # sol[-1] = max_amount
            for _j in coins:
                if _j <= _a:
                    sol[-1] = min(sol[-1], 1 + sol[_a - _j])
        if sol[amount] < max_amount:
            return sol[amount]
        else:
            return -1
            
        
"""
https://leetcode.com/problems/coin-change/

This is a DP problem. 
2 ideas for DP:
1. sol[-1] = min(sol[-1], sol[j] + sol[amount - j])
2. sol[-1] = min(sol[-1], 1 + sol[amount - coin[j])

The second one is faster. We applied it. 
"""