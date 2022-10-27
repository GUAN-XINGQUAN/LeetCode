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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
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
    n3->next = nullptr;

    Solution sol;

    if (sol.hasCycle(head))
        cout << "YES\n";
    else
        cout << "No\n";
}