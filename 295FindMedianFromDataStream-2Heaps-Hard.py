import heapq
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.maxheap = []
        self.minheap = []
        heapq.heapify(self.maxheap)
        heapq.heapify(self.minheap)
        

    def addNum(self, num: int) -> None:
        if not self.maxheap or num <= self.maxheap[0] * (-1):
            heapq.heappush(self.maxheap, -1 * num)
        else:
            heapq.heappush(self.minheap, num)
        
        if len(self.maxheap) > len(self.minheap) + 1:
            heapq.heappush(self.minheap, -1 * heapq.heappop(self.maxheap))
        elif len(self.minheap) > len(self.maxheap):
            heapq.heappush(self.maxheap, -1 * heapq.heappop(self.minheap))        

    def findMedian(self) -> float:
        if len(self.maxheap) == len(self.minheap):
            return (self.minheap[0] + (self.maxheap[0] * (-1))) * 1.0 / 2
        else:
            return -1 * self.maxheap[0]          


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

"""
https://leetcode.com/problems/find-median-from-data-stream/
2 heaps. Python (min) heap is too tricky: line 15.
"""