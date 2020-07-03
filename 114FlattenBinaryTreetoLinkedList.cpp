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


// Preorder traverse: recursive solution
class Solution1 {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
            flatten(root->left);
        if (root->right != nullptr)
            flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right != nullptr)
            root = root->right;
        root->right = temp;
    }
};

// Preorder traverse: non-recursive solution
class Solution2 {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                TreeNode* temp = cur->left;
                while (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                temp->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};


// Divide and conquer (recommended)
class Solution {
public:
    void flatten(TreeNode* root) {

    }
    TreeNode* getLastNode(TreeNode* root)
    {
        if 
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);

    TreeNode* t11 = new TreeNode(2);
    TreeNode* t12 = new TreeNode(3);

    TreeNode* t21 = new TreeNode(4);
    TreeNode* t22 = new TreeNode(5);
    TreeNode* t23 = new TreeNode(6);
    TreeNode* t24 = new TreeNode(7);

    root->left = t11;
    root->right = t12;
    t11->left = t21;
    t11->right = t22;
    t12->left = t23;
    t12->right = t24;

    Solution sol;

    sol.flatten(root);

    visualizeTreeInPreorder(root);
}