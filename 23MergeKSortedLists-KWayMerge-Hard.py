# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        ans = None
        heap = list()
        heapq.heapify(heap)
        for node in lists:
            while node:
                heapq.heappush(heap, node.val)
                node = node.next
        firstNode = True
        prevNode = None
        while heap:
            val = heapq.heappop(heap)
            obj = ListNode(val)
            if not ans:
                ans = obj
            if not firstNode:
                prevNode.next = obj
            prevNode = obj
            firstNode = False
        return ans
"""
https://leetcode.com/problems/merge-k-sorted-lists/
KWay Merge(heap)
"""