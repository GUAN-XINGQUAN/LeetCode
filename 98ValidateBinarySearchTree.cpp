#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<cassert>

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
 
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return helper(root, LONG_MIN, LONG_MAX);
	}
	bool helper(TreeNode* cur, long min, long max)
	{
		if (cur == nullptr)
			return true;
		if (cur->val <= min || cur->val >= max)
			return false;
		return helper(cur->left, min, cur->val) && helper(cur->right, cur->val, max);
	}
};

int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	assert(sol.isValidBST(root));
}