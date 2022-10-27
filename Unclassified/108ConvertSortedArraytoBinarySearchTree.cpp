#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (nums.empty())
			return nullptr;
		int mid = nums.size() / 2;
		TreeNode* cur = new TreeNode(nums[mid]);
		vector<int> left(nums.begin(), nums.begin() + mid);
		vector<int> right(nums.begin() + mid + 1, nums.end());
		cur->left = sortedArrayToBST(left);
		cur->right = sortedArrayToBST(right);
		return cur;
	}
};

void InOrder(TreeNode* cur)
{
	if (cur == nullptr)
		return;
	InOrder(cur->left);
	cout << cur->val <<' ';
	InOrder(cur->right);
}


int main()
{
	vector<int> vec = { -10, -3, 0, 5, 9 };
	Solution sol;
	TreeNode* result = sol.sortedArrayToBST(vec);
	TreeNode* cur = result;
	InOrder(cur);
}