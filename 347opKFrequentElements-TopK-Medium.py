import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        di = dict()
        for num in nums:
            di[num] = di[num] + 1 if num in di else 1
        li = list()
        heapq.heapify(li)
        for num in di:
            heapq.heappush(li, (di[num] * (-1), num))
        ans = []
        for _ in range(k):
            ans.append(heapq.heappop(li)[1])
        return ans
"""
https://leetcode.com/problems/top-k-frequent-elements/
TopK(heap)
"""