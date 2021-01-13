# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ans = []
        if not root:
            return ans
        q = deque()
        q.append(root)
        while q:
            levelAns = []
            for _ in range(len(q)):
                curNode = q.popleft()
                levelAns.append(curNode.val)
                if curNode.left:
                    q.append(curNode.left)
                if curNode.right:
                    q.append(curNode.right)
            ans.append(levelAns)
        return ans

"""
https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/
BFS
"""