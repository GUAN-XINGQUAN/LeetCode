# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heapLen = len(lists)
        heap = list()
        heapq.heapify(heap)
        # cnt is needed because of 
        # https://bit.ly/3rqjBKw
        cnt = 0
        for head in lists:
            if head:
                heapq.heappush(heap, (head.val, cnt, head))
                cnt += 1
        
        if not heap:
            return None
        
        ansHead = None
        ansCur = None
        while heap:
            _, _, smallest = heapq.heappop(heap)
            if ansCur:
                ansCur.next = smallest
            ansCur = smallest
            if not ansHead:
                ansHead = smallest
            if smallest.next:
                heapq.heappush(heap, (smallest.next.val, cnt, smallest.next))
                cnt += 1
        ansCur.next = None
        return ansHead
"""
https://leetcode.com/problems/merge-k-sorted-lists/
KWay Merge. 
O(NlogK). 
N = num of total element
K = num of list
"""