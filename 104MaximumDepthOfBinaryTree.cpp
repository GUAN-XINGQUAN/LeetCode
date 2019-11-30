#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Method 1: use recursion for DFS
//class Solution {
//public:
//	int maxDepth(TreeNode* root) {
//		if (root == nullptr)
//			return 0;
//		return 1 + max(maxDepth(root->left), maxDepth(root->right));
//	}
//};


// Method 2: use loop to count the layers of the tree
class Solution {
public:
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		queue<TreeNode*> qu;
		qu.push(root);
		int res = 0;
		while (!qu.empty())
		{
			res++;
			for (int i = qu.size(); i > 0; i--)
			{
				TreeNode* t = qu.front();
				qu.pop();
				if (t->left != nullptr)
					qu.push(t->left);
				if (t->right != nullptr)
					qu.push(t->right);
			}
		}
		return res;
	}
};



int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);

	root->left = node1;
	root->right = node2;
	node2->left = node3;
	node2->right = node4;

	Solution sol;

	int result = sol.maxDepth(root);

	cout << "The maximum depth is: " << result << endl;
}