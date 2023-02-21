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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr)
        {
            ListNode* nextNode = cur->next;
            if (nextNode->val == cur->val)
            {
                cur->next = nextNode->next;
                nextNode = nextNode->next;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};



/*
    1   1   1
    c
        n
    1       1



*/