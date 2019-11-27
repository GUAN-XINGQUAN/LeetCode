#include <iostream>
#include <vector>
#include <string>

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
	vector<string> binaryTreePaths(TreeNode* root) {
		// Use Depth-first-search algorithm
		vector<string> result;
		if (root == nullptr)
			return result;
		string str = "";
		DFS(root, result, str);
		return result;
	}
	// vector of result should be passed by reference to revise its values
	void DFS(TreeNode* cur, vector<string>& result, string path) {
		path += to_string(cur->val);
		if (cur->left == nullptr && cur->right == nullptr)
		{
			result.push_back(path);
			return;
		}
		if (cur->left != nullptr)
			DFS(cur->left, result, path+"->");
		if (cur->right != nullptr)
			DFS(cur->right, result, path+"->");
	}
};


int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);

	Solution sol;
	vector<string> result = sol.binaryTreePaths(root);

	// Display the result
	vector<string>::iterator it = result.begin();
	while (it != result.end())
	{
		cout << *it << endl;
		it++;
	}
	
}