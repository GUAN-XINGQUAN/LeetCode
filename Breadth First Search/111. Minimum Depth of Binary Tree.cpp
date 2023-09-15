/*
BFS
when we finish one level: count + 1
if the node has no left and right children. return the count.
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int result = 1;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur->left == nullptr && cur->right == nullptr)
                    return result;
                if (cur->left != nullptr)
                    nodeQueue.push(cur->left);
                if (cur->right != nullptr)
                    nodeQueue.push(cur->right);
            }
            result++;
        }
        return result;
        
    }
};