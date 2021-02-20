import heapq
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.li = nums
        self.k = k
        heapq.heapify(self.li)
        while len(self.li) > self.k:
            heapq.heappop(self.li)

    def add(self, val: int) -> int:
        heapq.heappush(self.li, val)
        while len(self.li) > self.k:
            heapq.heappop(self.li)
        return self.li[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)

"""
https://leetcode.com/problems/kth-largest-element-in-a-stream/
TopK(heap). 
By stricting the size of the min heap within k,
heap[0] will always be the k-th largest element. 
"""