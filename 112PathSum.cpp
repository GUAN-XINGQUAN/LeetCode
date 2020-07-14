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
// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// Solution 1:
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return pathHelper(root, sum);
    }
    bool pathHelper(TreeNode* node, int sum)
    {
        if (node == nullptr)
            return false;
        if (node->left == nullptr && node->right == nullptr && node->val == sum)
            return true;
        return pathHelper(node->left, sum - node->val) || pathHelper(node->right, sum - node->val);
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

    if (sol.hasPathSum(head, sum))
        cout << "YES\n";
    else
        cout << "NO\n";

}