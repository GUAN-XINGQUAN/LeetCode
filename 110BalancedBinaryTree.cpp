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
// Time complexity: O(N log N)
class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getDepth(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
};


// Solution 2:
// Time complexity: O(N)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (checkDepth(root) == -1)
            return false;
        return true;
    }
    int checkDepth(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        int left = checkDepth(node->left);
        if (left == -1)
            return -1;
        int right = checkDepth(node->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        else
            return 1 + max(left, right);
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

    Solution sol;
    if (sol.isBalanced(head))
        cout << "YES\n";
    else
        cout << "No\n";
}