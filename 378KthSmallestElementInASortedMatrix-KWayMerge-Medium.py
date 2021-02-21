import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        if k == 1:
            return matrix[0][0]
        cnt = 1
        heap = list()
        visited = set()
        heapq.heapify(heap)
        if len(matrix) > 1:
            heapq.heappush(heap, (matrix[1][0], 1, 0))
            visited.add((1, 0))
        if len(matrix[0]) > 1:
            heapq.heappush(heap, (matrix[0][1], 0, 1))
            visited.add((0, 1))
        ans = (matrix[0][0], 0, 0)
        while cnt < k:
            cnt += 1
            ans = heapq.heappop(heap)
            ansX = ans[1]
            ansY = ans[2]
            
            for direction in [(1, 0), (0, 1)]:
                newX = ansX + direction[0]
                newY = ansY + direction[1]
                if newX < len(matrix) and newY < len(matrix[0]) and (newX, newY) not in visited:
                    heapq.heappush(heap, (matrix[newX][newY], newX, newY))
                    visited.add((newX, newY))
        return ans[0]
"""
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
KWay Merge(heap)
Care for duplicates. 
"""