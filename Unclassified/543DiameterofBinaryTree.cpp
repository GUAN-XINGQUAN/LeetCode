#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int d = depth(root, res);
        return res;
    }
    int depth(TreeNode* node, int& res)
    {
        if (node == nullptr)
            return 0;
        if (node2Depth.count(node))
            return node2Depth[node];
        int leftDepth = depth(node->left, res);
        int rightDepth = depth(node->right, res);
        res = max(res, leftDepth+rightDepth);
        node2Depth[node] = 1 + max(depth(node->left, res), depth(node->right, res));
        return node2Depth[node];
    }
private:
    unordered_map<TreeNode*, int> node2Depth;
};

int main()
{
    Solution sol;

}