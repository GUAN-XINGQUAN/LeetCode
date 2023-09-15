/*
Typical BFS problem. Should solve it in short time and bug-free pattern.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            vector<int> level;
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur->left != nullptr)
                    nodeQueue.push(cur->left);
                if (cur->right != nullptr)
                    nodeQueue.push(cur->right);
                level.push_back(cur->val);
            }
            result.push_back(level);
        }
        return result;
    }
};