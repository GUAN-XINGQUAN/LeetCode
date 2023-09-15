/*
Adapted typical BFS problem.
Only difference is that we need to track if current layer is odd or even. 
If even, save each node in sequence. Otherwise, save each node in reverse order.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> nodeQueue ({root});
        vector<vector<int>> result;
        int layer = 0;
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur->left != nullptr)
                    nodeQueue.push(cur->left);
                if (cur->right != nullptr)
                    nodeQueue.push(cur->right);
                if (layer % 2 == 0)
                    level.push_back(cur->val);
                else
                    level.insert(level.begin(), cur->val);
            }
            layer++;
            result.push_back(level);
        }
        return result;
    }
};