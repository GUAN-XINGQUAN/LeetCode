#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
#include "treeVisualizationinPreorder.h"

using namespace std;

// Use iteration rather than recursion
class Solution1
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        invertHelper(root);
        return root;
    }
    
    void invertHelper(TreeNode* node)
    {
        if (node == nullptr)
            return;
        if (node->left != nullptr && node->right != nullptr)
        {
            TreeNode* tempNode = node->right;
            node->right = node->left;
            node->left = tempNode;
        }
        else if (node->left == nullptr && node->right != nullptr)
        {
            node->left = node->right;
            node->right = nullptr;
        }
        else if (node->left != nullptr && node->right == nullptr)
        {
            node->right = node->left;
            node->left = nullptr;
        }
        else
            return;
        invertHelper(node->left);
        invertHelper(node->right);
    }
};

// simplified version of recursion
class Solution2 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return nullptr;
		TreeNode* temp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(temp);
		return root;
	}
};

int main()
{
    TreeNode* root = new TreeNode(4);
    TreeNode* t11 = new TreeNode(2);
    TreeNode* t12 = new TreeNode(7);
    TreeNode* t21 = new TreeNode(1);
    TreeNode* t22 = new TreeNode(3);
    TreeNode* t23 = new TreeNode(6);
    TreeNode* t24 = new TreeNode(9);

    root->left = t11;
    root->right = t12;

    t11->left = t21;
    t11->right = t22;

    t12->left = t23;
    t12->right = t24;

    Solution sol;

    sol.invertTree(root);

    visualizeTreeInPreorder(root);

}