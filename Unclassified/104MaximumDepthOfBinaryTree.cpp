#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"


using namespace std;

// Approach 1: DFS with recursion
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


// Approach 2: BFS with iterative solution
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> nodeQueue({ root });
        int count = 0;

        while (!nodeQueue.empty())
        {
            for (int i = nodeQueue.size(); i > 0; i--)
            {
                TreeNode* temp = nodeQueue.front();
                nodeQueue.pop();
                if (temp->left != nullptr)
                    nodeQueue.push(temp->left);
                if (temp->right != nullptr)
                    nodeQueue.push(temp->right);
            }
            count++;
        }
        return count;
    }
};


// Approach 3: BFS with recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        vector<vector<int>> nodeVal;
        helper(root, 0, nodeVal);
        return nodeVal.size();
    }
    void helper(TreeNode* node, int depth, vector<vector<int>>& nodeVal)
    {
        if (depth == nodeVal.size())
            nodeVal.push_back({});
        nodeVal[depth].push_back(node->val);
        if (node->left != nullptr)
            helper(node->left, depth + 1, nodeVal);
        if (node->right != nullptr)
            helper(node->right, depth + 1, nodeVal);
    }
};

int main()
{

    TreeNode* root = new TreeNode(1);
    TreeNode* t11 = new TreeNode(2);
    TreeNode* t12 = new TreeNode(2);

    head->left = t11;
    head->right = t12;

    Solution sol;

    int res = sol.maxDepth(root);

    cout << res << endl;
  
}