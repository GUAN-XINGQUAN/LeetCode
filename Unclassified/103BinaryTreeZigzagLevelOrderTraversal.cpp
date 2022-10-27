#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

#include "NestedVectorVisualization.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive solution:
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        levelTraverse(root, 0, res);
        return res;
    }
    void levelTraverse(TreeNode* node, int depth, vector<vector<int>>& res)
    {
        if (node == nullptr)
            return;
        if (depth == res.size())
            res.push_back({});
        if (depth % 2 == 0)
            res[depth].push_back(node->val);
        else
            res[depth].insert(res[depth].begin(), node->val);
        if (node->left != nullptr)
            levelTraverse(node->left, depth + 1, res);
        if (node->right != nullptr)
            levelTraverse(node->right, depth + 1, res);
    }
};

// Iterative solution:
class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q({ root });
        int count = 0;
        while (!q.empty())
        {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode* node = q.front();
                q.pop();
                if (count % 2 == 0)
                    oneLevel.push_back(node->val);
                else
                    oneLevel.insert(oneLevel.begin(), node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            count++;
            res.push_back(oneLevel);
        }
        return res;
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* n11 = new TreeNode(9);
    TreeNode* n12 = new TreeNode(20);
    TreeNode* n21 = new TreeNode(15);
    TreeNode* n22 = new TreeNode(7);

    root->left = n11;
    root->right = n12;
    n12->left = n21;
    n12->right = n22;

    Solution2 sol;

    vector<vector<int>> res = sol.zigzagLevelOrder(root);

    // User-defined function to visualize the nested vectors
    nestedVectorVisualization(res);
}