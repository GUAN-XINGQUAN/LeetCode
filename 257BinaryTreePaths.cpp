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

// Divide and conquer 
// (this coding style is confused since multiple variable path is used inconsistently)
class Solution1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<string> vec;
        helper(root, "", vec);
        return vec;
    }
    void helper(TreeNode* node, string path, vector<string>& vec)
    {
        if (node->left == nullptr && node->right == nullptr)
            vec.push_back(path + to_string(node->val));
        if (node->left != nullptr)
            helper(node->left, path + to_string(node->val) + "->", vec);
        if (node->right != nullptr)
            helper(node->right, path + to_string(node->val) + "->", vec);
    }
};

// This coding style is better since the variable path is used consistently.
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<string> res;
        dfsHelper(root, {}, res);

        return res;
    }
    void dfsHelper(TreeNode* node, vector<int> path, vector<string>& res)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            path.push_back(node->val);
            string p = joinCharwithArrow(path);
            res.push_back(p);
        }

        if (node->left != nullptr)
        {
            path.push_back(node->val);
            dfsHelper(node->left, path, res);
            path.pop_back();
        }

        if (node->right != nullptr)
        {
            path.push_back(node->val);
            dfsHelper(node->right, path, res);
            path.pop_back();
        }
        return;
    }

    string joinCharwithArrow(vector<int> path)
    {
        if (path.size() == 0)
            return "";
        if (path.size() == 1)
            return to_string(path[0]);
        string res = "";
        for (int i = 0; i < path.size(); i++)
        {
            res += to_string(path[i]);
            if (i != path.size() - 1)
                res += "->";
        }
        return res;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);

    TreeNode* t11 = new TreeNode(2);
    TreeNode* t12 = new TreeNode(3);

    TreeNode* t21 = new TreeNode(5);
    //TreeNode* t22 = new TreeNode(2);
    //TreeNode* t23 = new TreeNode(0);
    //TreeNode* t24 = new TreeNode(8);

    //TreeNode* t31 = new TreeNode(7);
    //TreeNode* t32 = new TreeNode(4);

    root->left = t11;
    root->right = t12;

    t11->left = t21;
    //t11->right = t22;

    //t12->left = t23;
    //t12->right = t24;

    //t22->left = t31;
    //t22->right = t32;

    Solution sol;

    vector<string> res = sol.binaryTreePaths(root);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}