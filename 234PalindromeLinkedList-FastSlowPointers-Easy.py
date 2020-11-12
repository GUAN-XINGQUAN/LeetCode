# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # Caution! We're changing the original node to obtain O(1), which is against the idea of OOD. 
        if not head:
            return True # Fuck who can know this
        if not head.next:
            return True
        slow = head
        fast = head
        toLeft = None
        toRight = None
        slow.prev = None
        while True:
            if fast.next == None:
                toLeft = slow
                toRight = slow
                break
            fast = fast.next
            if fast.next == None:
                toLeft = slow
                toRight = slow.next
                break
            fast = fast.next
            slow.next.prev = slow
            slow = slow.next # if there are 2 median, slow will be the left one, with a prev attribute
        while True:
            if toLeft.val != toRight.val:
                return False
            if toLeft.prev == None:
                return True
            toLeft = toLeft.prev
            toRight = toRight.next
            
"""
https://leetcode.com/problems/palindrome-linked-list/
Fast & Slow Pointer problem. This might not be a "good" solution. 
"""