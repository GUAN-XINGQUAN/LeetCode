# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        p1 = l1
        p2 = l2
        v1 = p1.val
        v2 = p2.val
        h = None
        r = 0
        p = None
        while(True):
            v = v1 + v2 + r
            r = v // 10
            v = v % 10                
            
            temp = ListNode(v, None)
            if not h:
                h = temp
            else:
                p.next = temp
            p = temp
            
            if not p1.next and not p2.next and r == 0:
                break
            if p1.next:
                p1 = p1.next
                v1 = p1.val
            else:
                v1 = 0
            if p2.next:
                p2 = p2.next
                v2 = p2.val
            else:
                v2 = 0
        return h

"""
https://leetcode.com/problems/add-two-numbers/submissions/

I think the most complex part is how to handle the "residual nodes", 
especially when all of them are 9s and we have a residual of 1 by that time. 

I tried to solve that outside the while loop,
but that was to complicated. 
Alternatively, I combined them inside the while loop since there was some residual-handling methods inside. 
I applied v1 and v2 to represent the values of p1 and p2, instead of using p1/p2 directly, since they might be None. 
"""