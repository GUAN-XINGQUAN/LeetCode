# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        cnt = 1
        current = head
        previous = None
        preM = None
        M = None
        postN = None
        N = None
        while current:
            if cnt < m - 1:
                current = current.next
                pass
            elif cnt == m - 1:
                preM = current
                current = current.next
            elif cnt > n + 1:
                previous = current
                current = current.next
                pass
            elif cnt == n + 1:
                postN = current
                previous = current
                current = current.next
            else:
                if cnt == n:
                    N = current
                elif cnt == m:
                    M = current
                nextNode = current.next
                current.next = previous
                previous = current
                current = nextNode                
            cnt += 1
        if m != 1:
            preM.next = N
        M.next = postN
        if m == 1:
            return N
        else:
            return head
"""
https://leetcode.com/problems/reverse-linked-list-ii/
In-place Linked List Reversal. It's finally over... 
"""