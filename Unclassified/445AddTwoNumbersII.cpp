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

// Naive approach: 
// reverse two linked lists and then do the summation
// reverse the summation
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse the list
        ListNode* head1 = reverseList(l1);
        ListNode* head2 = reverseList(l2);
        // add them together
        ListNode* dummy = new ListNode(-1), * cur = dummy;
        int carry = 0;
        while (head1 != nullptr || head2 != nullptr)
        {
            int a = 0, b = 0;
            if (head1 != nullptr)
            {
                a = head1->val;
                head1 = head1->next;
            }
            if (head2 != nullptr)
            {
                b = head2->val;
                head2 = head2->next;
            }
            int sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        if (carry > 0)
            cur->next = new ListNode(carry);
        // reverse the summation
        ListNode* head = dummy->next;
        ListNode* res = reverseList(head);
        return res;
    }
    ListNode* reverseList(ListNode* head)
    {
        // edge case
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr, * cur = head;
        while (cur != nullptr)
        {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};

// follow up: you are not allowed to reverse the linked list.
// remember we need to handle the least significant digit first, which is the end of the list
// then we can use stack to deal with.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> nodeStack1, nodeStack2;
        stack<int> sumStack;
        // store the linked list into two stacks
        while (l1 != nullptr)
        {
            nodeStack1.push(l1);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            nodeStack2.push(l2);
            l2 = l2->next;
        }
        // store the summation into a stack
        int carry = 0;
        while (!nodeStack1.empty() || !nodeStack2.empty())
        {
            int a = 0, b = 0;
            if (!nodeStack1.empty())
            {
                a = nodeStack1.top()->val;
                nodeStack1.pop();
            }
            if (!nodeStack2.empty())
            {
                b = nodeStack2.top()->val;
                nodeStack2.pop();
            }
            int sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            sumStack.push(sum);
        }
        if (carry > 0)
            sumStack.push(carry);
        // convert the stack into list
        ListNode* dummy = new ListNode(-1), * cur = dummy;
        while (!sumStack.empty())
        {
            cur->next = new ListNode(sumStack.top());
            sumStack.pop();
        }
        return dummy->next;
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

    ListNode* res = sol.reverseList(head);
    while (res != nullptr)
    {
        cout << res->val << endl;
        res = res->next;
    }

}