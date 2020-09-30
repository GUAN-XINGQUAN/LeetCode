class Solution:
    def partitionLabels(self, S):
        max_idx = dict()
        ans = list()
        for _i, _c in enumerate(S):
            max_idx[_c] = _i
        start = 0
        end = 0
        for _i, _c in enumerate(S):
            _max_idx = max_idx[_c]
            if _max_idx > end:
                end = _max_idx
            if end == _i:
                ans.append(end - start + 1)
                start = _i + 1
        return ans
            
"""
https://leetcode.com/problems/partition-labels/submissions/

Always find the max possible idx for current substring. 
If that idx is the end of current substring, that means we've found it.
Open another new substring at next idx. 
"""