/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(val+1);
        ListNode* cur = dummy;
        dummy->next = head;
        while (cur != nullptr && cur->next != nullptr)
        {
            ListNode* nextNode = cur->next;
            if (nextNode->val == val)
            {
                cur->next = nextNode->next;
                nextNode = nextNode->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};


/*
val = 2

    1   2   2   3   2   1   4

    1   



*/