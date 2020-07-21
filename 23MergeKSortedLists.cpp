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

// Approach 1: divide and conquer
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // edge case
        if (lists.empty())
            return nullptr;

        // divide and conquer
        int n = lists.size();
        while (n > 1)
        {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            n = k;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != nullptr)
            cur->next = l1;
        else
            cur->next = l2;
        return dummy->next;
    }
};

// Approach 2: use heap
//bool compare(ListNode* l1, ListNode* l2)
//{
//    if (l1->val < l2->val)
//        return true;
//    else
//        return false;
//}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode*& a, ListNode*& b) {
            return a->val > b->val;
        };
        priority_queue < ListNode*, vector<ListNode*>, decltype(compare)> pQ(compare);
        for (ListNode* each : lists)
        {
            if (each != nullptr)
                pQ.push(each);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!pQ.empty())
        {
            ListNode* temp = pQ.top();
            pQ.pop();
            cur->next = temp;
            cur = cur->next;
            if (cur->next != nullptr)
                pQ.push(cur->next);
        }
        return dummy->next;
    }
};

// Main program to test
int main()
{
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);

    vector<ListNode*> vec = { head1, head2, head3 };
    Solution sol;
    ListNode* res = sol.mergeKLists(vec);
    cout << res->val;
}