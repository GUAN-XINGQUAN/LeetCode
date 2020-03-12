#include<iostream>

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
			return true;
		if (p == nullptr && q != nullptr)
			return false;
		if (p != nullptr && q == nullptr)
			return false;
		if (p->val != q->val)
			return false;
		bool res = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		return res;
	}
};

int main()
{
	Solution sol;
	TreeNode* p = new TreeNode(1);
	TreeNode* q = new TreeNode(1);
	p->left = new TreeNode(2);
	q->left = new TreeNode(2);

	if (sol.isSameTree(p, q))
		cout << "YES\n";
	else
		cout << "NO\n";
}