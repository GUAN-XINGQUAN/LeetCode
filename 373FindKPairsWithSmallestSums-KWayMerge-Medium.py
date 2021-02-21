import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = list()
        heapq.heapify(heap)
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                s = nums1[i] + nums2[j]
                if len(heap) < k:
                    heapq.heappush(heap, (s * (-1), nums1[i], nums2[j]))
                else:
                    if s > heap[0][0] * (-1):
                        break
                    else:
                        heapq.heappop(heap)
                        heapq.heappush(heap, (s * (-1), nums1[i], nums2[j]))
        ans = []
        while heap:
            elem = heapq.heappop(heap)
            ans.append([elem[1], elem[2]])
        return ans
"""
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
KWay Merge. Pruning is necessary in our case. 
"""