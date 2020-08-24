#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
 #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        string res = "";
        queue<TreeNode*> nodeQueue({ root });
        
        while (!nodeQueue.empty())
        {
            TreeNode* temp = nodeQueue.front();
            nodeQueue.pop();
            if (temp != nullptr)
            {
                res += to_string(temp->val) + " ";
                nodeQueue.push(temp->left);
                nodeQueue.push(temp->right);
            }
            else
                res += "# ";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        queue<TreeNode*> nodeQueue;
        // isstringstream: extract string from data
        istringstream is(data);
        string val;
        is >> val;
        TreeNode* res = new TreeNode(stoi(val));
        TreeNode* cur = res;

        nodeQueue.push(cur);

        while (!nodeQueue.empty())
        {
            TreeNode* temp = nodeQueue.front();
            nodeQueue.pop();
            is >> val;
            if (val.empty())
                break;
            if (val != "#")
            {
                cur = new TreeNode(stoi(val));
                nodeQueue.push(cur);
                temp->left = cur;
            }
            is >> val;
            if (val.empty())
                break;
            if (val != "#")
            {
                cur = new TreeNode(stoi(val));
                nodeQueue.push(cur);
                temp->right = cur;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main()
{
    TreeNode* root = new TreeNode(10);
    
    TreeNode* n11 = new TreeNode(2);
    TreeNode* n12 = new TreeNode(3);

    TreeNode* n21 = new TreeNode(4);
    TreeNode* n22 = new TreeNode(5);

    root->left = n11;
    root->right = n12;
    n12->left = n21;
    n12->right = n22;

    Codec codec;

    string res = codec.serialize(root);
    
    TreeNode* head = codec.deserialize(res);

    visualizeTreeInPreorder(head);
}