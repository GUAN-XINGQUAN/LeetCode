# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return None
        slow = head
        fast = head.next
        while True:
            slow = slow.next
            if fast.next:
                fast = fast.next
            else:
                return None
            if fast.next:
                fast = fast.next
            else:
                return None
            if slow == fast:
                break
        cnt = 0
        firstEncounter = True
        while fast != slow or firstEncounter:
            firstEncounter = False
            fast = fast.next
            cnt += 1
        slow = head
        fast = head
        while cnt > 0:
            fast = fast.next
            cnt -= 1
        while fast != slow:
            fast = fast.next
            slow = slow.next
        return slow
    
"""
https://leetcode.com/problems/linked-list-cycle-ii/
Fast & Slow Pointers
Key idea: find interval 
"""