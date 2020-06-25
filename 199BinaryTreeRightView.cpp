#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorCharVisualization.h"

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

// BFS: use level order
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> valueVec;
        queue<TreeNode*> nodeQueue({ root });
        while (!nodeQueue.empty())
        {
            valueVec.push_back(nodeQueue.back()->val);
            int size = nodeQueue.size();
            for (int i = size; i > 0; i--)
            {
                TreeNode* tempNode = nodeQueue.front();
                nodeQueue.pop();
                if (tempNode->left != nullptr)
                    nodeQueue.push(tempNode->left);
                if (tempNode->right != nullptr)
                    nodeQueue.push(tempNode->right);
            }
        }
        return valueVec;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* l11 = new TreeNode(2);
    TreeNode* l12 = new TreeNode(3);
    TreeNode* l21 = new TreeNode(5);
    TreeNode* l22 = new TreeNode(4);
    root->left = l11;
    root->right = l12;
    l11->right = l21;
    l12->right = l22;

    Solution sol;

    vector<int> res = sol.rightSideView(root);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';    
}