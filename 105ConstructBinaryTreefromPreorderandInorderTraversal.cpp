#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"

using namespace std;

// Recursion
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head = buildHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return head;
    }
    TreeNode* buildHelper(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight)
    {
        // preorder or inorder become empty
        if (pLeft > pRight || iLeft > iRight)
            return nullptr;
        int i = 0;
        for (i = iLeft; i <= iRight; i++)
        {
            if (inorder[i] == preorder[pLeft])
                break;
        }
        // now i is the index in inorder vector that points to root node
        TreeNode* node = new TreeNode(preorder[pLeft]);
        node->left = buildHelper(preorder, pLeft+1, pLeft+i-iLeft, inorder, iLeft, i-1);
        node->right = buildHelper(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return node;

    }
};

int main()
{
    vector<int> preorder = { 1,2,4,3,5 };
    vector<int> inorder = { 4,2,1,3,5 };
    Solution sol;

    TreeNode* head = sol.buildTree(preorder, inorder);

    visualizeTreeInPreorder(head);
}