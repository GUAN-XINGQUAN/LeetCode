# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head == None:
            return False
        if head.next == None:
            return False
        slow = head
        fast = head.next
        while True:
            slow = slow.next
            if fast.next == None:
                return False
            fast = fast.next
            if fast.next == None:
                return False
            fast = fast.next
            if hash(slow) == hash(fast):
                return True
"""
https://leetcode.com/problems/linked-list-cycle/submissions/
Fast & Slow pointers
"""