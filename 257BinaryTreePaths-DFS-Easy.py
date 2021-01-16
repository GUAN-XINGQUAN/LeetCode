# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []
    def binaryTreePaths(self, root: TreeNode, ans=[], ifRoot=True) -> List[str]:
        if not root:
            return []
        if root.left == None and root.right == None:
            self.ans.append(ans + [str(root.val)])
        self.binaryTreePaths(root.left, ans + [str(root.val)], False)
        self.binaryTreePaths(root.right, ans + [str(root.val)], False)
        if ifRoot:
            ans = []
            for path in self.ans:
                ans.append("->".join(path))
            return ans
"""
https://leetcode.com/problems/binary-tree-paths/
DFS. 
"""