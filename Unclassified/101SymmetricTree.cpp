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

// Recursive solution
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return symmetricHelper(root->left, root->right);
    }
    bool symmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr) || (left->val != right->val))
            return false;
        return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
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