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

// Time complexity O(N), space complexity O(N)
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        // edge case
        if (head == nullptr)
            return true;
        vector<int> nodeVal;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            nodeVal.push_back(temp->val);
            temp = temp->next;
        }
        int left = 0, right = nodeVal.size() - 1;
        while (left < right)
        {
            if (nodeVal[left] != nodeVal[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};


// Follow up: time complexity O(N), space complexity O(1)
// Reverse the later half of the linked list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // edge case
        if (head == nullptr || head->next == nullptr)
            return true;
        // use two pointers to find the middle
        ListNode* slow = head, * fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the later half of the linked list
        ListNode* last = slow->next;
        while (last->next != nullptr)
        {
            ListNode* temp = last->next;
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }
        // Now slow is the dummy head of the later half
        ListNode* node = head;
        while (slow->next != nullptr)
        {
            slow = slow->next;
            if (slow->val != node->val)
                return false;
            node = node->next;
        }
        return true;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(1);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution sol;

    if (sol.isPalindrome(head))
        cout << "YES\n";
    else
        cout << "NO\n";
}