from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        ans = []
        for i in range(len(nums)):
            # if q and q[0] + k - 1 > i:
            if q and q[0] + k <= i:
                q.popleft()
            while q:
                if nums[q[-1]] < nums[i]:
                    q.pop()
                else:
                    break
            q.append(i)
            if i + 1 >= k:
                ans.append(nums[q[0]])
        return ans
    
"""
https://leetcode.com/problems/sliding-window-maximum/
"""