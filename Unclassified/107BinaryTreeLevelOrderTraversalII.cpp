#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

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

// Non-recursive solution
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q({ root });
        while (!q.empty())
        {
            vector<int> oneLevel;
            for (int i = q.size() - 1; i >= 0; i--)
            {
                TreeNode* node = q.front();
                q.pop();
                oneLevel.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};

// Recursive solution
class Solution2 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelTraverse(root, 0, res);
        return vector<vector<int>> (res.rbegin(), res.rend());
    }
    void levelTraverse(TreeNode* node, int depth, 
        vector<vector<int>>& res)
    {
        if (node == nullptr)
            return;
        if (depth == res.size())
            res.push_back({});
        res[depth].push_back(node->val);
        if (node->left != nullptr)
            levelTraverse(node->left, depth + 1, res);
        if (node->right != nullptr)
            levelTraverse(node->right, depth + 1, res);
    }

};

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* l11 = new TreeNode(9);
    TreeNode* l12 = new TreeNode(20);
    TreeNode* l21 = new TreeNode(15);
    TreeNode* l22 = new TreeNode(7);

    root->left = l11;
    root->right = l12;
    l12->left = l21;
    l12->right = l22;

    Solution2 sol;
    vector<vector<int>> res = sol.levelOrderBottom(root);

    // Visualize the results
    vector<vector<int>>::iterator it1 = res.begin();
    while (it1 != res.end())
    {
        vector<int>::iterator it2 = it1->begin();
        while (it2 != it1->end())
        {
            cout << *it2 << "\t";
            it2++;
        }
        cout << endl;
        it1++;
    }
}