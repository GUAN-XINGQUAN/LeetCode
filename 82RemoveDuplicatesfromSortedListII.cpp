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
#include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        while (pre->next != nullptr)
        {
            ListNode* cur = pre->next;
            while (cur->next != nullptr && cur->next->val == cur->val)
                cur = cur->next;
            if (cur != pre->next)
                pre->next = cur->next;
            else
                pre = pre->next;
        }
        return dummy->next;
    }
};


int main()
{
    Solution sol;

    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(3);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    ListNode* res = sol.deleteDuplicates(head);
    listNodeVisualization(res);
}