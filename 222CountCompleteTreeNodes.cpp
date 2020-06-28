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

// O(N) solution ==> convert a tree into a vector and count the length (not recommended)
class Solution1 {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        // In level traverse
        vector<int> nodeVec;
        queue<TreeNode*> nodeQueue({ root });
        while (!nodeQueue.empty())
        {
            TreeNode* tempNode = nodeQueue.front();
            nodeQueue.pop();
            nodeVec.push_back(tempNode->val);
            if (tempNode->left != nullptr)
                nodeQueue.push(tempNode->left);
            if (tempNode->right != nullptr)
                nodeQueue.push(tempNode->right);
        }
        int count = nodeVec.size();
        return count;
    }
};


// Follow up: avoid using additional vector as a space.
// Use recursion to discover the depth.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftDepth = 1, rightDepth = 1;
        TreeNode* tempNode1 = root;
        while (tempNode1->left != nullptr)
        {
            leftDepth++;
            tempNode1 = tempNode1->left;
        }
        TreeNode* tempNode2 = root;
        while (tempNode2->right != nullptr)
        {
            rightDepth++;
            tempNode2 = tempNode2->right;
        }
        if (leftDepth == rightDepth)
            return int(pow(2, leftDepth) - 1);
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
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

    root->left = t11;
    root->right = t12;
    t11->left = t21;
    t11->right = t22;
    t22->left = t23;

    Solution sol;

    int res = sol.countNodes(root);

    cout << res << endl;
}