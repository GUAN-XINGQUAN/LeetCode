#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
#include "listNodeVisualization.h"

using namespace std;

// two pointers
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // edge case
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* oddHead = head, * evenHead = head->next, * cur = evenHead->next;
        ListNode* copyHead = evenHead;
        int count = 1;
        while (cur != nullptr)
        {
            // odd
            if (count % 2 != 0)
            {
                oddHead->next = cur;
                oddHead = oddHead->next;
            }
            // even
            else
            {
                evenHead->next = cur;
                evenHead = evenHead->next;
            }
            cur = cur->next;
            count++;
        }
        if (count % 2 == 0)
            evenHead->next = nullptr;
        else
            oddHead->next = nullptr;
        oddHead->next = copyHead;
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    ListNode* res = sol.oddEvenList(head);
    listNodeVisualization(res);
}