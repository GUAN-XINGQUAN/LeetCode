class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = list()
        start = newInterval[0]
        end = newInterval[1]
        ifInserted = False
        for i in range(len(intervals)):
            interval = intervals[i]
            curStart = interval[0]
            curEnd = interval[1]
            if ifInserted or curEnd < start or curStart > end:
                if curStart > end and not ifInserted:
                    ans.append([start, end])
                    ifInserted = True
                ans.append([curStart, curEnd])
            elif curEnd >= start >= curStart or curStart <= end <= curEnd:
                start = min(start, curStart)
                end = max(end, curEnd)
        if not ifInserted:
            ans.append([start, end])
        return ans
"""
https://leetcode.com/problems/insert-interval/
Merging Intervals
"""