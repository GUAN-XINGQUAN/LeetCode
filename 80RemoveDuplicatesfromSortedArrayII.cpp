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
#include "listNodeVisualization.h"

using namespace std;

// Revise the orignial linked list
class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        // edge case
        if (head == nullptr)
            return nullptr;
        // linear scan to find the first node with value > x
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, * cur = head;
        while (pre->next != nullptr && pre->next->val < x)
            pre = pre->next;
        cur = pre;
        while (cur->next != nullptr)
        {
            if (cur->next->val < x)
            {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
                pre = pre->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};

// Create a new list to append all nodes with values < x
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return nullptr;
        ListNode* dummy = new ListNode(-1);
        ListNode* myDummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy, * myCur = myDummy;
        while (cur->next != nullptr)
        {
            if (cur->next->val < x)
            {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                myCur->next = temp;
                temp->next = nullptr;
                myCur = myCur->next;
            }
            else
                cur = cur->next;
        }
        myCur->next = dummy->next;
        return myDummy->next;
    }
};


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(2);
    
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution sol;

    ListNode* res = sol.partition(head, 3);

    listNodeVisualization(res);
}