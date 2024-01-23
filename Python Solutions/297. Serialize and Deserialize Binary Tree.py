# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Use BFS and reverse-BFS for the approach.
"""

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        # Encode is a standard BFS problem
        if root is None:
            return "#"
        nodeQueue = collections.deque([root])
        result = ""
        while nodeQueue:
            curNode = nodeQueue.popleft()
            if curNode is not None:
                result += str(curNode.val) + ","
                nodeQueue.append(curNode.left)
                nodeQueue.append(curNode.right)
            else:
                result += "#" + ","
        result = result[:-1]  # the last char is ",", so remove it
        return result

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # Decode edge case
        if data == "#":
            return None
        # Decode standard case
        # start building the root node
        strArray = data.split(",")  # either a string of number or "#"
        # the 0-idex element must be a number because of edge case handling
        root = TreeNode(strArray[0])  
        # use a BFS to do parent node -> left child -> right child
        nodeQueue = collections.deque([root])
        # 0-index node has been created 
        idx = 1  
        while idx < len(strArray):
            # this node will be parent
            curNode = nodeQueue.popleft()  
            # Let's focus on left child
            leftVal = strArray[idx]
            if leftVal == "#":
                leftChild = None
            else:
                # don't forget to convert from str to int
                leftChild = TreeNode(int(leftVal))
                # This left child must be in queue because it will be parent for next layer
                nodeQueue.append(leftChild)
            # connect parent with left child
            curNode.left = leftChild
            idx += 1

            # focus on right child: repeat the same process
            rightVal = strArray[idx]
            if rightVal == "#":
                rightChild = None
            else:
                rightChild = TreeNode(int(rightVal))
                nodeQueue.append(rightChild)
            curNode.right = rightChild
            idx += 1
        return root
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))