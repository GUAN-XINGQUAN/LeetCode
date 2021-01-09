# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k == 1 or not head or not head.next:
            return head
        current = head
        last0 = None
        current0 = None
        cnt = 0
        while current:
            if cnt % k == 0:
                # Judge if there are at least k following nodes. 
                kCnt = 0
                kCurrent = current
                while kCurrent:
                    kCnt += 1
                    if kCnt == k:
                        break
                    kCurrent = kCurrent.next
                if kCnt < k:
                    current0.next = current
                    return head                
                if cnt // k > 0:
                    last0 = current0
                
                current0 = current
                previous = None
            
            if cnt % k == k - 1 and cnt // k > 0:
                last0.next = current
            if cnt % k == k - 1 and cnt // k == 0:
                head = current
            
            nextNode = current.next
            current.next = previous
            previous = current  
            current = nextNode          
            
            cnt += 1
        return head            
"""
https://leetcode.com/problems/reverse-nodes-in-k-group/
In-place Linked List Reversal. 
"""