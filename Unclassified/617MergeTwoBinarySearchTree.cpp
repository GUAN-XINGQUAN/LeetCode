#include<iostream>
#include<queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* result = nullptr;
		mergeHelper(t1, t2, result);
		return result;
	}
	void mergeHelper(TreeNode* t1, TreeNode* t2, TreeNode*& result)
	{
		if (t1 == nullptr && t2 == nullptr)
			return;
		else if (t1 != nullptr && t2 == nullptr)
		{
			result = new TreeNode(t1->val);
			mergeHelper(t1->left, nullptr, result->left);
			mergeHelper(t1->right, nullptr, result->right);
		}
		else if (t1 == nullptr && t2 != nullptr)
		{
			result = new TreeNode(t2->val);
			mergeHelper(nullptr, t2->left, result->left);
			mergeHelper(nullptr, t2->right, result->right);
		}
		else
		{
			result = new TreeNode(t1->val + t2->val);
			mergeHelper(t1->left, t2->left, result->left);
			mergeHelper(t1->right, t2->right, result->right);
		}
	}
};


int main()
{
	// Construct Tree 1
	TreeNode* root0 = new TreeNode(1);
	TreeNode* left10 = new TreeNode(3);
	TreeNode* right10 = new TreeNode(2);
	TreeNode* left20 = new TreeNode(5);

	root0->left = left10;
	root0->right = right10;
	left10->left = left20;

	// Construct Tree 2
	TreeNode* root1 = new TreeNode(2);
	TreeNode* left11 = new TreeNode(1);
	TreeNode* right11 = new TreeNode(3);
	TreeNode* right21 = new TreeNode(4);
	TreeNode* right22 = new TreeNode(7);

	root1->left = left11;
	root1->right = right11;
	left11->right = right21;
	right11->right = right22;

	// Display the result: level-order traversal
	Solution sol;
	TreeNode* root = sol.mergeTrees(root0, root1);
	TreeNode* cur = root;
	queue<TreeNode*> q;
	q.push(cur);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		cout << cur->val << '\t';
		if (cur->left != nullptr)
			q.push(cur->left);
		if (cur->right != nullptr)
			q.push(cur->right);
	}
}