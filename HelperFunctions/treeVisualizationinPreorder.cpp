#include<iostream>
#include "treeVisualizationinPreorder.h"

using namespace std;

void visualizeTreeInPreorder(TreeNode* root)
{
	if (root == nullptr)
		return;
	cout << root->val << '\t';
	if (root->left != nullptr)
		visualizeTreeInPreorder(root->left);
	if (root->right != nullptr)
		visualizeTreeInPreorder(root->right);
}