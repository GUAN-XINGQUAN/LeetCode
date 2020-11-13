# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return
        slow = head
        fast = head
        rev = None
        while True:
            if not fast.next:
                rev = slow.next
                slow.next = None
                break # actual median (slow)
            fast = fast.next
            if not fast.next:
                rev = slow.next # actually, slow.next.next will be enought. just to make things clear.
                slow.next = None
                break # left median (slow)
            fast = fast.next
            slow = slow.next # slow will always be the left median.
        
        prev = None
        revRight = None
        while rev != None:
            revRight = rev.next
            rev.next = prev
            prev = rev
            rev = revRight
        # Then prev will be the right most node
        exe = head
        while prev != None:
            exePrevNext = exe.next
            exe.next = prev
            prev = prev.next
            exe.next.next = exePrevNext
            exe = exe.next.next
        return 
"""
https://leetcode.com/problems/reorder-list/
This question is the same with 234. 
"""