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

// Inorder traverse and store in a vector
// recursive solution
class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodeVal;
        inOrderTraverse(root, nodeVal);
        return nodeVal[k - 1];
    }
    void inOrderTraverse(TreeNode* node, vector<int>& nodeVal)
    {
        if (node == nullptr)
            return;
        if (node->left != nullptr)
            inOrderTraverse(node->left, nodeVal);
        nodeVal.push_back(node->val);
        if (node->right != nullptr)
            inOrderTraverse(node->right, nodeVal);
    }
};

// Non recursive solution
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* dummy = new TreeNode(-1);
        dummy->right = root;
        stack<TreeNode*> nodeStack({ dummy });
        
        for (int i = 0; i < k; i++)
        {
            TreeNode* tempNode = nodeStack.top();
            nodeStack.pop();
            if (tempNode->right != nullptr)
            {
                tempNode = tempNode->right;
                while (tempNode != nullptr)
                {
                    nodeStack.push(tempNode);
                    tempNode = tempNode->left;
                }
            }
            if (nodeStack.empty())
                break;
        }
        // unnecessary edge case
        if (nodeStack.empty())
            return -1;
        return nodeStack.top()->val;
    }
};


// Divide and conquer
// Rely on the property of BST
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int numNodesLeftBranch = countNodes(root->left);
        if (k < numNodesLeftBranch + 1)
            return kthSmallest(root->left, k);
        else if (k > numNodesLeftBranch + 1)
            return kthSmallest(root->right, k);
        return root->val;
    }
    int countNodes(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
};


// Follow up: what if the BST has been revised frequently
// Define a new struct of TreeNode

struct newTreeNode
{
    int val;
    int count;  // the number of nodes in the tree which uses current node as the root
    newTreeNode* left;
    newTreeNode* right;
    
    newTreeNode(int x) : val(x), count(1), left(nullptr), right(nullptr);
};

// Reconstruct the tree using exisiting tree
newTreeNode* buildNewTree(TreeNode* root)
{
    // edge case
    if (root == nullptr)
        return nullptr;
    // recursively build a tree
    newTreeNode* newRoot = new newTreeNode(root->val);
    newRoot->left = buildNewTree(root->left);
    newRoot->right = buildNewTree(root->right);
    if (newRoot->left != nullptr)
        newRoot->count += newRoot->left->count;
    if (newRoot->right != nullptr)
        newRoot->count += newRoot->right->count;
    return newRoot;
}


class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        newTreeNode* newRoot = buildNewTree(root);

    }
    int countNodes(newTreeNode* newNode, int k)
    {
        if (newNode->left != nullptr)
        {
            int count = newNode->left->count;
            if (k < count + 1)
            {
                return countNodes(newNode->left, k);
            }
            else if (k > count + 1)
                return countNodes(newNode->right, k-1-count);
            else
            {
                return newNode->val;
            }
        }
        else
        {
            if (k == 1)
                return newNode->val;
            return countNodes(newNode->right, k-1);
        }
    }
};


int main()
{
    TreeNode* root = new TreeNode(5);

    TreeNode* t11 = new TreeNode(3);
    TreeNode* t12 = new TreeNode(6);

    TreeNode* t21 = new TreeNode(2);
    TreeNode* t22 = new TreeNode(4);

    root->left = t11;
    root->right = t12;
    t11->left = t21;
    t11->right = t22;

    Solution sol;

    int res = sol.kthSmallest(root, 1);

    cout << res << endl;
}