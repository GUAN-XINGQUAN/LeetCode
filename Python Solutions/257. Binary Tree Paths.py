# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Approach #1: use depth first search to achieve backtrack
    start with the root node.
    
    base case: 
        if it is a leaf node --> save all path into the result

    general case:
        if left child is valid --> left child in current path AND move to left 
    
        if right child is valid --> right child in current path AND move to right

    However, when take one step back from left child to parent, we also need to pop out the left child from current path. Otherwise, when we go to right child, the left child is still in our current path.

Approach #2: use divide and conquer:
    (1) Imagine there is a black box function that gives all the path from current node to leaf nodes.
    (2) We can use this function on left branch and right branch recursively.
    (3) Then the path from current node to all leaf nodes is to append current node to all the paths from (2)
"""

# Approach #1
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root is None:
            return []
        path, result = [str(root.val)], []
        self.dfs(root, path, result)
        return result

    def dfs(self, root, path, result):
        if root.left is None and root.right is None:
            result.append("->".join(path))
            return
        
        if root.left:
            path.append(str(root.left.val))
            self.dfs(root.left, path, result)
            path.pop()   # be cautious here!!!
        
        if root.right:
            path.append(str(root.right.val))
            self.dfs(root.right, path, result)
            path.pop()  # be cautious here!!!

# Approach #2
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        return self.divideAndConquer(root)

    def divideAndConquer(self, root) -> List[str]:
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [str(root.val)]
        
        allPaths = []
        leftPaths = self.divideAndConquer(root.left)
        rightPaths = self.divideAndConquer(root.right)

        for path in leftPaths:  # path is a string
            allPaths.append(str(root.val) + "->" + path)
        for path in rightPaths:
            allPaths.append(str(root.val) + "->" + path)

        return allPaths