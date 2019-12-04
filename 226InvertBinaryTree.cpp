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

// Method 1: use recursion
//class Solution {
//public:
//	TreeNode* invertTree(TreeNode* root) {
//		if (root == nullptr)
//			return nullptr;
//		TreeNode* temp = root->left;
//		root->left = invertTree(root->right);
//		root->right = invertTree(temp);
//		return root;
//	}
//};

// Method 2: use for loop with queue
class Solution
{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == nullptr)
			return nullptr;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			TreeNode* temp = cur->left;
			cur->left = cur->right;
			cur->right = temp;
			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
		}
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(4);
	TreeNode* layer10 = new TreeNode(2);
	TreeNode* layer11 = new TreeNode(7);
	TreeNode* layer20 = new TreeNode(1);
	TreeNode* layer21 = new TreeNode(3);
	TreeNode* layer22 = new TreeNode(6);
	TreeNode* layer23 = new TreeNode(9);

	root->left = layer10;
	root->right = layer11;
	layer10->left = layer20;
	layer10->right = layer21;
	layer11->left = layer22;
	layer11->right = layer23;

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* cur = q.front();
		q.pop();
		if (cur->left != nullptr)
			q.push(cur->left);
		if (cur->right != nullptr)
			q.push(cur->right);
		cout << cur->val << '\t';
	}
	cout << endl;

	Solution sol;
	TreeNode* newRoot = sol.invertTree(root);
	q.push(newRoot);
	while (!q.empty())
	{
		TreeNode* cur = q.front();
		q.pop();
		if (cur->left != nullptr)
			q.push(cur->left);
		if (cur->right != nullptr)
			q.push(cur->right);
		cout << cur->val << '\t';
	}
}