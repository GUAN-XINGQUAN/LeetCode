"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

"""
Since each node has a pointer to its parent and both p and q exist in the tree. We can view this problem as a linked list problem.

Let's imagine there are two linked list starting with node p and q.

We don't know where each of the linked list goes to. We want to see where they firstly intersect (they will surely intersect at the root).

Let's denote the distance from p to the intersection as disP; distance from q to intersection as disQ. Then the distance from the intersection to root is denoted as disR.

We could have the following equation:
    disP + disR + disQ = disQ + disR + disP

We can view left side as the moving path of node p; right side as the path of node q.

Then, the rationale behind the equation actaully tells us:
    (1) we move p and q at the same pace
    (2) when p comes to the root, make it to q. 
    (3) when q comes to the root, make it to p.
    (4) then when they meet each other, that is the intersection.
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        return self.helper(p, q)

    def helper(self, p, q):
        curP, curQ = p, q
        while curP and curQ:
            if curP == curQ:
                return curP
            # focus on p
            if curP.parent is None:
                curP = q
            else:
                curP = curP.parent
            # focus on q
            if curQ.parent is None:
                curQ = p
            else:
                curQ = curQ.parent
        return None  # p and q exist in the tree, so this should not be reached