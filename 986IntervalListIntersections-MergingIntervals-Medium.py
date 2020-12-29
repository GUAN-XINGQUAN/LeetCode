class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        ans = []
        ia = 0
        ib = 0
        while ia <= len(A) - 1 and ib <= len(B) - 1:
            startA = A[ia][0]
            endA = A[ia][1]
            startB = B[ib][0]
            endB = B[ib][1]
            if startB <= startA <= endB  or startB <= endA <= endB or startA <= startB <= endA or startA <= endB <= endA:
                ans.append([max(startA, startB), min(endA, endB)])
            if endA < endB:
                ia += 1
            else:
                ib += 1
        return ans
"""
https://leetcode.com/problems/interval-list-intersections/
Merging Intervals. 
* How to judge the 2 intervals are overlapping, and
* When to move to the next interval. 
"""