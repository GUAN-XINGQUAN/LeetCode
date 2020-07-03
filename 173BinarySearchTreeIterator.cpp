#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "treeVisualizationinPreorder.h"

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// next() and hasNext() should run in average O(1) time and uses O(h) memory
// where h is the height of the tree.
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode* tempNode = root;
        while (tempNode != nullptr)
        {
            nodeStack.push(tempNode);
            tempNode = tempNode->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tempNode = nodeStack.top();
        nodeStack.pop();
        int minimum = tempNode->val;
        // Don't forget to push the right branch into stack
        if (tempNode->right != nullptr)
        {
            tempNode = tempNode->right;
            while (tempNode != nullptr)
            {
                nodeStack.push(tempNode);
                tempNode = tempNode->left;
            }
        }
        return minimum;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (nodeStack.empty())
            return false;
        else
            return true;
    }
private:
    stack<TreeNode*> nodeStack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    TreeNode* root = new TreeNode(7);
    TreeNode* t11 = new TreeNode(3);
    TreeNode* t12 = new TreeNode(15);
    TreeNode* t21 = new TreeNode(9);
    TreeNode* t22 = new TreeNode(20);

    root->left = t11;
    t12->left = t21;
    t12->right = t22;

    BSTIterator* obj = new BSTIterator(root);
    int res1 = obj->next();

    cout << res1 << endl;

    if (obj->hasNext())
        cout << "has next small value\n";
    else
        cout << "NO\n";
}