from collections import deque
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if k == 0:
            return []
        if len(arr) <= k:
            return arr
        
        
        MAX = 2 * 10 ** 4 + 1
        leftIdx = 0
        rightIdx = len(arr) - 1
        midIdx = None
        while leftIdx <= rightIdx:
            midIdx = (leftIdx + rightIdx) // 2
            midVal = arr[midIdx]
            if leftIdx == rightIdx:
                break
            if midVal == x:
                break
            elif midVal < x:
                leftIdx = midIdx + 1
            else:
                rightIdx = midIdx                
                
        ans = deque()
        minVal = MAX
        minIdx = midIdx
        for shift in [-1, 0, 1]:
            idx = midIdx + shift
            if 0 <= idx <= len(arr) - 1:
                curAbs = abs(arr[idx] - x)
                if curAbs < minVal:
                    minIdx = idx
                    minVal = curAbs
        ans.append(arr[minIdx])
        midIdx = minIdx
        leftIdx = midIdx
        rightIdx = midIdx 
        
        while len(ans) < k:
            leftVal = MAX
            rightVal = MAX
            if leftIdx > 0:
                leftVal = abs(arr[leftIdx - 1] - x)
            if rightIdx < len(arr) - 1:
                rightVal = abs(arr[rightIdx + 1] - x)
                
            if leftVal < rightVal:
                ans.appendleft(arr[leftIdx - 1])
                leftIdx -= 1
            elif rightVal < leftVal:
                ans.append(arr[rightIdx + 1])
                rightIdx += 1
            elif rightVal < MAX:
                ans.appendleft(arr[leftIdx - 1])
                leftIdx -= 1
            else: # leftVal == rightVal == MAX
                break
        return ans
"""
https://leetcode.com/problems/find-k-closest-elements/submissions/
Binary Search
"""                   