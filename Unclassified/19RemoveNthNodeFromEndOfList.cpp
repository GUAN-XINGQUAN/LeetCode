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

// Do it with two pass
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Remeber n is alway valid
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return nullptr;

        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }

        int index = count - n;
        if (index == 0)
        {
            ListNode* myHead = head->next;
            myHead->next = head->next->next;
            delete head;
            return myHead;
        }

        ListNode* cur = head;
        ListNode* pre = head;
        for (int i = 0; i < index; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        if (cur->next != nullptr)
        {
            pre->next = cur->next;
            delete cur;
        }
        else
            pre->next = nullptr;
        return head;
    }
};

// Follow up: do it with one pass
// Two pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < n; i++)
            cur = cur->next;
        if (cur == nullptr)
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while (cur->next != nullptr)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = cur;
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* t1 = new ListNode(2);
    ListNode* t2 = new ListNode(3);
    ListNode* t3 = new ListNode(4);
    ListNode* t4 = new ListNode(5);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    
    Solution sol;

    ListNode* res = sol.removeNthFromEnd(head, 2);

    listNodeVisualization(res);
}