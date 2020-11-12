# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head.next:
            return head
        
        slow = head
        fast = head
        while True:
            if fast.next == None:
                return slow
            fast = fast.next
            if fast.next == None:
                return slow.next
            fast = fast.next
            slow = slow.next
                
"""
https://leetcode.com/problems/middle-of-the-linked-list/
Fast & Slow Pointers
"""       