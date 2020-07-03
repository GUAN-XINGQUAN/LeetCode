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

// Recursion
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

// Non recursive solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr)
        {
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else
                break;
        }
        return root;
    }
};

int main()
{
    TreeNode* root = new TreeNode(6);

    TreeNode* t11 = new TreeNode(2);
    TreeNode* t12 = new TreeNode(8);

    TreeNode* t21 = new TreeNode(0);
    TreeNode* t22 = new TreeNode(4);
    TreeNode* t23 = new TreeNode(7);
    TreeNode* t24 = new TreeNode(9);

    TreeNode* t31 = new TreeNode(3);
    TreeNode* t32 = new TreeNode(5);

    root->left = t11;
    root->right = t12;

    t11->left = t21;
    t11->right = t22;

    t12->left = t23;
    t12->right = t24;

    t22->left = t31;
    t22->right = t32;

    Solution sol;
    
    TreeNode* res = sol.lowestCommonAncestor(root, t11, t22);
    
    cout << res->val << endl;
}