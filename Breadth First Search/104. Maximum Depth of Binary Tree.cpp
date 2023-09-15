/*
Typical BFS problem.
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int result = 0;
        queue<TreeNode*> nodeQueue ({root});
        while (!nodeQueue.empty())
        {   
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
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