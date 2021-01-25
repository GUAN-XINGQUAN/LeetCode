class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        if len(intervals) == 1:
            return [-1]
        byEnd = []
        byStart = []
        for idx in range(len(intervals)):
            interval = intervals[idx]
            byEnd.append([interval[0], interval[1], idx])
            byStart.append([interval[0], interval[1], idx])
        byEnd.sort(key=lambda x:x[1])
        byStart.sort(key=lambda x:x[0], reverse=True)
        
        ans = [-1 for _ in range(len(intervals))]
        prevIdx = -1
        for interval in byEnd:
            curEnd = interval[1]
            while prevIdx >= -1 * len(intervals) and byStart[prevIdx][0] < curEnd:
                prevIdx -= 1
            if prevIdx < -1 * len(intervals):
                return ans
            elif byStart[prevIdx][0] >= curEnd:
                ans[interval[2]] = byStart[prevIdx][2]
        return ans
"""
https://leetcode.com/problems/find-right-interval/
2 Heaps. It's actually 2 sorted arrs.
"""