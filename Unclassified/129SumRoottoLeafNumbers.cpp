#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

// User defined function to visualize 2D array.
// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = DFS(root, 0);
        return res;
    }
    int DFS(TreeNode* node, int sum)
    {
        if (node == nullptr)
            return 0;
        sum = sum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr)
            return sum;
        return DFS(node->left, sum) + DFS(node->right, sum);
    }
};

int main()
{
    TreeNode* head = new TreeNode(1);
    TreeNode* t11 = new TreeNode(2);
    TreeNode* t12 = new TreeNode(3);
    TreeNode* t21 = new TreeNode(4);
    TreeNode* t22 = new TreeNode(5);

    head->left = t11;
    head->right = t12;
    t11->left = t21;
    t11->right = t22;

    Solution sol;

    int res = sol.sumNumbers(head);

    cout << res << endl;
}