import heapq
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        if k > len(Profits):
            k = len(Profits)
        h = []
        heapq.heapify(h)
        minCap = 65536
        for i in range(len(Profits)):
            heapq.heappush(h, (-1 * Profits[i], Capital[i]))
            minCap = min(minCap, Capital[i])
        if not Profits or W < minCap:
            return W
        while k > 0:
            k -= 1
            passed = []
            while h and W < h[0][1]:
                passed.append(heapq.heappop(h))
            if not h:
                return W
            W += -1 * h[0][0]
            heapq.heappop(h)
            for elem in passed:
                heapq.heappush(h, elem)
        return W
"""
https://leetcode.com/problems/ipo/
Heap.
"""