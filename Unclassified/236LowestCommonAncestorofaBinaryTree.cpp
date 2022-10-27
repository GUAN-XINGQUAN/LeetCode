#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"

using namespace std;

// Be cautious: this is not a binary search tree, jut a binary tree!
// p and q must exist.
// Divide and conquer
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
        if (leftNode != nullptr && rightNode != nullptr)
            return root;
        else if (leftNode != nullptr)
            return leftNode;
        else
            return rightNode;

    }
};

int main()
{
    TreeNode* root = new TreeNode(3);

    TreeNode* t11 = new TreeNode(5);
    TreeNode* t12 = new TreeNode(1);

    TreeNode* t21 = new TreeNode(6);
    TreeNode* t22 = new TreeNode(2);
    TreeNode* t23 = new TreeNode(0);
    TreeNode* t24 = new TreeNode(8);

    TreeNode* t31 = new TreeNode(7);
    TreeNode* t32 = new TreeNode(4);

    root->left = t11;
    root->right = t12;

    t11->left = t21;
    t11->right = t22;

    t12->left = t23;
    t12->right = t24;

    t22->left = t31;
    t22->right = t32;

    Solution sol;
    
    TreeNode* res = sol.lowestCommonAncestor(root, t21, t22);
    
    cout << res->val << endl;
}