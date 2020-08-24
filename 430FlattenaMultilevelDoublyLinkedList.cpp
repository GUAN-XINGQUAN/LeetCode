#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        Node* cur = head;
        while (cur != nullptr)
        {
            if (cur->child != nullptr)
            {
                Node* next = cur->next;
                Node* last = cur->child;
                while (last->next != nullptr)
                    last = last->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;
                last->next = next;
                if (next != nullptr)
                    next->prev = last;
            }
            cur = cur->next;
        }
        return head;
    }
};


int main()
{
    Solution sol;

    
}