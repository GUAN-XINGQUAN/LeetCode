#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode* head = new ListNode(-999);
		ListNode* current = head;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				current->next = l1;
				l1 = l1->next;
			}
			else
			{
				current->next = l2;
				l2 = l2->next;
			}
			current = current->next;
		}
		if (l1 == nullptr)
			current->next = l2;
		else
			current->next = l1;
		return head->next;
	}
};