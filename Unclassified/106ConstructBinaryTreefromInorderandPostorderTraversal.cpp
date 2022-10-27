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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* head = buildHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        return head;
    }
    TreeNode* buildHelper(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight)
    {
        // empty inorder or postorder case
        if (iLeft > iRight || pLeft > pRight)
            return nullptr;
        int i = 0;
        for (i = iLeft; i <= iRight; i++)
        {
            if (inorder[i] == postorder[pRight])
                break;
        }
        // index i is the root
        TreeNode* node = new TreeNode(postorder[pRight]);
        node->left = buildHelper(inorder, iLeft, i-1, postorder, pLeft, pLeft+i-1-iLeft);
        node->right = buildHelper(inorder, i+1, iRight, postorder, pLeft + i - iLeft, pRight-1);
        return node;
    }
};

int main()
{
    vector<int> inorder = { 4,2,1,3,5 };
    vector<int> postorder = { 4,2,5,3,1 };
    Solution sol;

    TreeNode* head = sol.buildTree(inorder, postorder);

    visualizeTreeInPreorder(head);
}