/*
Typical DFS problem: recursive approach and stack-based approach.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
	    if (root == nullptr)
			return {};
        vector<int> result;
		dfs(root, result);
		return result;
    }

	void dfs(TreeNode* node, vector<int>& nodeValues)
	{
		if (node->left != nullptr)
			dfs(node->left, nodeValues);
		nodeValues.push_back(node->val);
		if (node->right != nullptr)
			dfs(node->right, nodeValues);
	}

};

// iterative solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        stack<TreeNode*> nodeStack;
        TreeNode* cur = root;
        vector<int> result;
        while (cur != nullptr || !nodeStack.empty())
        {
            while (cur != nullptr)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            cur = nodeStack.top();
            nodeStack.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
		return result;
    }
};