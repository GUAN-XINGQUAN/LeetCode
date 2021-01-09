# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        current = head
        nodeCnt = 0
        while current.next:
            current = current.next
            nodeCnt += 1
        current.next = head
        nodeCnt += 1
        k = nodeCnt - (k % nodeCnt)
        current = head
        while k > 1:
            current = current.next
            k -= 1
        ans = current.next
        current.next = None
        return ans
"""
https://leetcode.com/problems/rotate-list/
In-place Linked List Reversal. 
"""