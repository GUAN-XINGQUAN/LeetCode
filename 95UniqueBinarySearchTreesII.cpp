#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;


// Recursive solution
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {  };
        vector<TreeNode*> res = generateHelper(1, n);
        return res;
    }
    vector<TreeNode*> generateHelper(int left, int right)
    {
        if (left > right)
            return vector<TreeNode*> {nullptr};
        vector<TreeNode*> res;
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode*> leftNode = generateHelper(left, i - 1);
            vector<TreeNode*> rightNode = generateHelper(i + 1, right);
            for (auto l : leftNode)
            {
                for (auto r : rightNode)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};


// Optimized approach: memorization
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {  };
        // memo[i][j] represents the number of trees between number i and j
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        vector<TreeNode*> res = generateHelper(1, n, memo);
        return res;
    }
    vector<TreeNode*> generateHelper(int left, int right, vector<vector<vector<TreeNode*>>> memo)
    {
        if (left > right)
            return vector<TreeNode*> {nullptr};
        if (!memo[left - 1][right - 1].empty())
            return memo[left - 1][right - 1];
        vector<TreeNode*> res;
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode*> leftNode = generateHelper(left, i - 1, memo);
            vector<TreeNode*> rightNode = generateHelper(i + 1, right, memo);
            for (auto l : leftNode)
            {
                for (auto r : rightNode)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        memo[left - 1][right - 1] = res;
        return res;
    }
};

int main()
{
	Solution sol;
    
}