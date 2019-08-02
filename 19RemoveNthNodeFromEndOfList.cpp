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
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = 0;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			len++;
			cur = cur->next;
		}
		int pos = len - n;
		ListNode* newCur = head;

		if (len == 1)
			return nullptr;

		int indx = 0;
		if (n == 1)
		{
			while (indx < pos-1)
			{
				newCur = newCur->next;
				indx++;
			}
			newCur->next = nullptr;
			return head;
		}
		else if (n == len)
		{
			return head->next;
		}
		else
		{
			while (indx < pos-1)
			{
				newCur = newCur->next;
				indx++;
			}
			newCur->next = newCur->next->next;
			return head;
		}
	}
};