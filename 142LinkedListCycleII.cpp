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

// Mathematical derivation:
// Distance from head to the beginning node of the circle: a1
// Distance from beginning node of the circle to meet location: a2
// Length of loop: aL
// Fast pointer moves twice than the slower pointer
// a1+a2+aL = 2(a1+a2)  ==> aL = a1+a2
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        fast = head;
        while (slow!=nullptr)
        {
            if (fast == slow)
                return fast;
            slow = slow->next;
            fast = fast->next;
        }
        return nullptr;
    }
};

int main()
{
    ListNode* head = new ListNode(3);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(0);
    ListNode* n3 = new ListNode(4);
    
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    Solution sol;

    ListNode* res = sol.detectCycle(head);
    if (res == nullptr)
        cout << "No cycle\n";
    else
        cout << res->val << endl;
}