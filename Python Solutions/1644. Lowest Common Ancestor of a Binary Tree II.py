# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Approach #1:
    Use divide and conquer.
    Let's design a function that takes root, p, q and find the LCA for p and q.
    In this function, we can assume that p and q surely exist in the tree, which is contradictionary to the problem statement but we can address this later.
    This function will do the following:
    (1) If it sees p or q or null, return the current node.
    (2) do the recursion on left branch and right branch separately
    (3) If both branch return valid node, then current node is the LCA. Otherwise, the side that has valid node is the LCA.
    However, as mentioned before, this function does not address the case where p or q does not exist in the tree.
    We can add one additional step: when we get the LCA from the function above, we traverse the tree starting from the LCA and see if both p and q exist. If so, LCA is final result. Otherwise, no LCA.

Approach #2:
    In approach #1, we need to do one additional step to check if both p and q exist. 
    Naturally, we came to a confusion: can we skip the last step and integrating such check when we find the LCA.
    In the function of searching LCA, we can add two additional return variables: hasP and hasQ to denote if p and q are found.

    The function still relies on recursion:
    (1) if the current node is None --> return None, False, False (LCA is None, p does not exit, q does not exist)
    (2) do recursion on left branch and right branch separately, we can 6 variables:
            leftLCA, leftHasP, leftHasQ
            rightLCA, rightHasP, rightHasQ
    (3) we need to generate the hasP and hasQ using the following rule:
            hasP = currentNode == p or leftHasP or rightHasP
            hasQ = currentNode == q or leftHasQ or rightHasQ
    (4) return the outcome case by case:
        (4.1) both leftLCA and rightLCA are valid --> return current node
        (4.2) otherwise, return the side that has valid node
    (5) outside recursion: 
        if hasP and hasQ are True --> return LCA
        else --> return None
"""
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # get the fake LCA
        lca = self.lca(root, p, q)
        # ensure both p and q is in the tree under LCA
        hasP = self.hasNode(lca, p)
        hasQ = self.hasNode(lca, q)
        if hasP and hasQ:
            return lca
        else:
            return None
    
    def hasNode(self, root: TreeNode, target: TreeNode) -> bool:
        if root is None:
            return False
        if root == target:
            return True
        return self.hasNode(root.left, target) or self.hasNode(root.right, target)

    def lca(self, root: TreeNode, p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
        if root is None or root == p or root == q:
            return root
        
        left = self.lca(root.left, p, q)
        right = self.lca(root.right, p, q)

        if left and right:
            return root
        elif left:
            return left
        elif right:
            return right
        else:
            return None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        hasP, hasQ, lca= self.helper(root, p, q)
        return lca if hasP and hasQ else None

    def helper(self, root: TreeNode, p: TreeNode, q: TreeNode) -> tuple[bool, bool, TreeNode]:
        if root is None:
            return False, False, None

        leftHasP, leftHasQ, leftLCA = self.helper(root.left, p, q)
        rightHasP, rightHasQ, rightLCA = self.helper(root.right, p, q)

        hasP = root == p or leftHasP or rightHasP
        hasQ = root == q or leftHasQ or rightHasQ

        if root == p or root == q:
            return hasP, hasQ, root

        if leftLCA and rightLCA:
            return hasP, hasQ, root
        elif leftLCA:
            return hasP, hasQ, leftLCA
        elif rightLCA:
            return hasP, hasQ, rightLCA
        else:
            return hasP, hasQ, None
