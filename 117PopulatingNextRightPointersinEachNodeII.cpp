#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

// User defined function to visualize 2D array.
// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// recursive solution
class Solution1 {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        // Find what's the next in the current level
        Node* nextP = root->next;
        while (nextP != nullptr)
        {
            if (nextP->left != nullptr)
            {
                nextP = nextP->left;
                break;
            }
            if (nextP->right != nullptr)
            {
                nextP = nextP->right;
                break;
            }
            nextP = nextP->next;
        }
        if (root->right != nullptr)
        {
            root->right->next = nextP;
        }
        if (root->left != nullptr)
        {
            if (root->right == nullptr)
                root->left->next = nextP;
            else
                root->left->next = root->right;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};

// iterative solution
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        queue<Node*> nodeQueue({ root });
        while (!nodeQueue.empty())
        {
            for (int i = nodeQueue.size(); i > 0; i--)
            {
                Node* temp = nodeQueue.front();
                nodeQueue.pop();
                if (i > 1)
                    temp->next = nodeQueue.front();
                if (temp->left != nullptr)
                    nodeQueue.push(temp->left);
                if (temp->right != nullptr)
                    nodeQueue.push(temp->right);
            }
        }
        return root;
    }
};