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
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


using namespace std;

// Approach 1: use hash table with non-recursive solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // edge case
        if (head == nullptr)
            return nullptr;

        // construct a hash table from old node to copy node
        Node* copyHead = new Node(head->val);
        Node* cur = head->next, * copyCur = copyHead;
        unordered_map<Node*, Node*> old2Copy;
        old2Copy[head] = copyHead;
        while (cur != nullptr)
        {
            Node* temp = new Node(cur->val);
            copyCur->next = temp;
            copyCur = copyCur->next;
            old2Copy[cur] = temp;
            cur = cur->next;
        }

        cur = head;
        copyCur = copyHead;

        while (cur != nullptr)
        {
            copyCur->random = old2Copy[cur->random];
            cur = cur->next;
            copyCur = copyCur->next;
        }

        return copyHead;

    }
};

int main()
{

}