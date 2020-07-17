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
#include "treeVisualizationinPreorder.h"
#include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        ListNode* slow = head, * fast = head, * last = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = nullptr;
        // slow points to the middle of the linked list
        TreeNode* node = new TreeNode(slow->val);
        if (head != slow)
            node->left = sortedListToBST(head);
        node->right = sortedListToBST(fast);
        return node;
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
    TreeNode* res = sol.sortedListToBST(head);

    visualizeTreeInPreorder(res);
}