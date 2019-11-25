#include <iostream>
#include <vector>
#include <stack>

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
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> result;
//		inorderHelper(root, result);
//		return result;
//	}
//	void inorderHelper(TreeNode* cur, vector<int>& track)
//	{
//		if (cur == nullptr)
//			return;
//		inorderHelper(cur->left, track);
//		track.push_back(cur->val);
//		inorderHelper(cur->right, track);
//	}
//};

// Method 2: don't use recursion: use stack
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != nullptr || !st.empty())
		{
			while (cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top();
			st.pop();
			result.push_back(cur->val);
			cur = cur->right;
		}
		return result;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution sol;
	vector<int> result = sol.inorderTraversal(root);
	vector<int>::iterator it = result.begin();
	while (it != result.end())
	{
		cout << *it << ' ';
		it++;
	}
}