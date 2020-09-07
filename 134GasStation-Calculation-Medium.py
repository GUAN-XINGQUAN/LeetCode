class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        glob = 0
        cur = 0
        start_idx = 0
        for _i in range(len(gas)):
            fill = gas[_i]
            consume = cost[_i]
            re = fill - consume
            glob += re
            cur += re
            if cur < 0:
                cur = 0
                start_idx = _i + 1
        if glob < 0:
            return -1
        else:
            return start_idx

"""
https://leetcode.com/problems/gas-station/

The key question is to calculate the residual list for each trip. 
As long as the sume of residual list is not negavie, there will be a solution.

"""