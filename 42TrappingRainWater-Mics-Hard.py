class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) < 3:
            return 0
        leftIdx = 0
        rightIdx = len(height) - 1
        leftMax = height[leftIdx]
        rightMax = height[rightIdx]
        ans = 0
        while leftIdx <= rightIdx:
            if leftMax > rightMax:
                if rightMax < height[rightIdx]:
                    rightMax = height[rightIdx]
                else:
                    # got trapped by rightMax
                    ans += rightMax - height[rightIdx]
                rightIdx -= 1
            else:
                if leftMax < height[leftIdx]:
                    leftMax = height[leftIdx]
                else:
                    # got trapped by leftMax
                    ans += leftMax - height[leftIdx]
                leftIdx += 1
        return ans
"""
https://leetcode.com/problems/trapping-rain-water/
Mics
"""