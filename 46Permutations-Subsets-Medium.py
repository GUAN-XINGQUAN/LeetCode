class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for i in range(len(nums)):
            num = nums[i]
            startIdx = 0
            endIdx = len(ans) - 1
            curAns = []
            for j in range(startIdx, endIdx + 1):
                prevAns = ans[j]
                for k in range(len(prevAns) + 1):
                    tmpAns = []
                    if k != 0:
                        tmpAns = prevAns[:k]
                    tmpAns.append(num)
                    if k < len(prevAns):
                        tmpAns = tmpAns + prevAns[k:]
                    curAns.append(tmpAns)
            ans = curAns
        return ans
"""
https://leetcode.com/problems/permutations/
Subsets. BFS. A recursive solution is also appreciated.
"""