import heapq
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        li = list()
        heapq.heapify(li)
        for elem in points:
            x = elem[0]
            y = elem[1]
            heapq.heappush(li, (x ** 2 + y ** 2, x, y))
        ans = []
        for _ in range(K):
            elem = heapq.heappop(li)
            ans.append([elem[1], elem[2]])
        return ans
"""
https://leetcode.com/problems/k-closest-points-to-origin/
TopK(heap)
"""