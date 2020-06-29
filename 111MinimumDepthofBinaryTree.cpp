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


// Non recursion
// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> nodeQueue({ root });
        int depth = 1;
        while (!nodeQueue.empty())
        {
            for (int i = nodeQueue.size(); i > 0; i--)
            {
                TreeNode* tempNode = nodeQueue.front();
                nodeQueue.pop();
                if (tempNode->left == nullptr && tempNode->right == nullptr)
                    return depth;
                if (tempNode->left != nullptr)
                    nodeQueue.push(tempNode->left);
                if (tempNode->right != nullptr)
                    nodeQueue.push(tempNode->right);
            }
            depth++;
        }
        return -1;
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);

    TreeNode* t11 = new TreeNode(9);
    TreeNode* t12 = new TreeNode(20);

    TreeNode* t21 = new TreeNode(15);
    TreeNode* t22 = new TreeNode(7);

    root->left = t11;
    root->right = t12;

    t12->left = t21;
    t12->right = t22;

    Solution sol;
    cout << sol.minDepth(root);
}
