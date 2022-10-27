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

// Recursive solution
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        if (root->left != nullptr)
        {
            root->left->next = root->right;
        }
        if (root->right != nullptr)
        {
            if (root->next != nullptr)
                root->right->next = root->next->left;
            else
                root->right->next = nullptr;
        }
        connect(root->left);
        connect(root->right);
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
            Node* temp = nodeQueue.front();
            nodeQueue.pop();
            if (temp->left != nullptr)
            {
                temp->left->next = temp->right;
                nodeQueue.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                if (temp->next != nullptr)
                    temp->right->next = temp->next->left;
                else
                    temp->right->next = nullptr;
                nodeQueue.push(temp->right);
            }
        }
        return root;
    }
};