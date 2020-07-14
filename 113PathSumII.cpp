#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

// User defined function to visualize 2D array.
#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return {};
        vector<int> out;
        vector<vector<int>> res;
        DFS(root, sum, out, res);
        return res;
    }
    void DFS(TreeNode* node, int sum, vector<int>& out, vector<vector<int>>& res)
    {
        if (node == nullptr)
            return;
        out.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && node->val == sum)
            res.push_back(out);
        DFS(node->left, sum - node->val, out, res);
        DFS(node->right, sum - node->val, out, res);
        out.pop_back();
    }
};


int main()
{
    TreeNode* head = new TreeNode(1);
    TreeNode* t11 = new TreeNode(2);
    TreeNode* t12 = new TreeNode(3);
    TreeNode* t21 = new TreeNode(4);
    TreeNode* t22 = new TreeNode(5);

    head->left = t11;
    head->right = t12;
    t11->left = t21;
    t11->right = t22;

    int sum = 8;

    Solution sol;

    vector<vector<int>> res = sol.pathSum(head, sum);
    
    nestedVectorIntVisualization(res);

}