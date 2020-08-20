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
        // edge case
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* pre = head, * cur = head->next;
        while (cur != nullptr)
        {
            if (cur->val == pre->val)
            {
                pre->next = pre->next->next;
                cur = cur->next;
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return head;
    }
};


int main()
{
    Solution sol;

    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;

    ListNode* res = sol.deleteDuplicates(head);
    listNodeVisualization(res);

}