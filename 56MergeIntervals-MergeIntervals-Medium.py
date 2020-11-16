class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = list()
        intervals.sort()
        for interval in intervals:
            if not ans:
                ans.append(interval)
            else:
                lastInterval = ans[-1]
                if interval[0] > lastInterval[1]:
                    ans.append(interval)
                elif interval[0] <= lastInterval[1] and interval[1] > lastInterval[1]:
                    ans[-1][-1] = interval[1]
                elif interval[0] <= lastInterval[1] and interval[1] <= lastInterval[1]:
                    pass 
        return ans
"""
https://leetcode.com/problems/merge-intervals/
Merge Intervals
"""