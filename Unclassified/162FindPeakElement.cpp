#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorIntVisualization.h"

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
 
// User in order traverse for the BST
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodeVec;
        inOrderHelper(root, nodeVec);
        return nodeVec[k-1];
    }
    void inOrderHelper(TreeNode* node, vector<int>& nodeVec)
    {
        if (node == nullptr)
            return;
        if (node->left!=nullptr)
            inOrderHelper(node->left, nodeVec);
        nodeVec.push_back(node->val);
        if (node->right != nullptr)
            inOrderHelper(node->right, nodeVec);
    }
};
int main()
{
    TreeNode* root = new TreeNode(10);
    TreeNode* t11 = new TreeNode(8);
    TreeNode* t12 = new TreeNode(13);
    TreeNode* t21 = new TreeNode(5);
    TreeNode* t22 = new TreeNode(9);
    TreeNode* t23 = new TreeNode(11);
    TreeNode* t24 = new TreeNode(15);

    root->left = t11;
    root->right = t12;
    t11->left = t21;
    t11->right = t22;
    t12->left = t23;
    t12->right = t24;

    Solution sol;

    int res = sol.kthSmallest(root, 0);
    cout << res << endl;

    //sol.inOrderHelper(root, res);
    //for (int i = 0; i < res.size(); i++)
    //    cout << res[i] << '\t';
}