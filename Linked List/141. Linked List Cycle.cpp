/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            cur = cur->next;
            fast = fast->next->next;
            if (cur == fast)
                return true;
        }
        return false;
    }
};