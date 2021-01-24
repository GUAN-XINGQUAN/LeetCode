import heapq
class Solution:
    def __init__(self):
        self.minheap = []
        self.maxheap = []
        heapq.heapify(self.minheap)
        heapq.heapify(self.maxheap)
        
    def heapBalance(self):
        if len(self.maxheap) > len(self.minheap) + 1:
            heapq.heappush(self.minheap, heapq.heappop(self.maxheap) * (-1))
            return
        while len(self.maxheap) < len(self.minheap):
            heapq.heappush(self.maxheap, heapq.heappop(self.minheap) * (-1))
        
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        leftIdx = 0
        rightIdx = 0
        ans = []
        while rightIdx < len(nums):
            
            # delete previous val
            if rightIdx >= k:
                leftVal = nums[leftIdx]                
                _mul = 1
                _heap = self.minheap
                if leftVal <= self.maxheap[0] * (-1):
                    _mul = -1
                    _heap = self.maxheap
                _idx = _heap.index(_mul * leftVal)
                _heap[_idx] = _heap[0]
                heapq.heapify(_heap)
                heapq.heappop(_heap)
                leftIdx += 1
                self.heapBalance()
            
            # insert new val
            rightVal = nums[rightIdx]
            if not self.maxheap or self.maxheap[0] * (-1) >= rightVal:
                heapq.heappush(self.maxheap, rightVal * -1)
            else:
                heapq.heappush(self.minheap, rightVal)
            self.heapBalance()
            rightIdx += 1
            if rightIdx <= k - 1:
                continue
            if len(self.maxheap) == len(self.minheap):
                ans.append((-1 * self.maxheap[0] + self.minheap[0]) * 1.0 / 2)
            else:
                ans.append(-1 * self.maxheap[0])            
        return ans
"""
https://leetcode.com/problems/sliding-window-median/
2 heaps.
"""