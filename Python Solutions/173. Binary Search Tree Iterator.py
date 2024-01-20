# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        """
        We need a stack to simulate the in-order traversal.
        The stack just keep tracking of the nodes along the left branch all the way to leaf.
        """
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        """
        The top element of the stack is the next element. 
        However, every time we pop out the top element, we need to think about the case where the current node (top element) has right branch.
        The right branch's leftmost leaf noode is the next element, which means we should push this to stack for the future usage.
        """
        nextNode = self.stack.pop()
        value = nextNode.val
        if nextNode.right:
            nextNode = nextNode.right
            while nextNode:
                self.stack.append(nextNode)
                nextNode = nextNode.left
        return value

    def hasNext(self) -> bool:
        """
        If the stack is empty --> no next element. Otherwise, has next one.
        """
        return len(self.stack) != 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()