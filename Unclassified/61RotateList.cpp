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
#include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // edge case
        if (head == nullptr)
            return nullptr;
        // count all nodes and get the tail
        int count = 1;
        ListNode* temp = head;
        while (temp->next != nullptr)
        {
            count++;
            temp = temp->next;
        }
        // become a circular linked list
        temp->next = head;
        int move = count - k % count - 1;
        ListNode* cur = head;
        for (int i = 0; i < move; i++)
            cur = cur->next;
        ListNode* newHead = cur->next;
        cur->next = nullptr;
        return newHead;
    }
};


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);
    
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution sol;

    ListNode* res = sol.rotateRight(head, 0);

    listNodeVisualization(res);

}