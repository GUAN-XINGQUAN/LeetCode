#include<iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k == 1)
			return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		for (int i = 1; cur != nullptr; i++)
		{
			if (i % k == 0)
			{
				pre = reverseOneGroup(pre, cur->next);
				cur = pre->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		return dummy->next;
	}
	ListNode* reverseOneGroup(ListNode* pre, ListNode* nxt)
	{
		ListNode* last = pre->next;
		ListNode* cur = last->next;
		while (cur != nxt)
		{
			last->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = last->next;
		}
		return last;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	Solution sol;
	ListNode* res = sol.reverseKGroup(head, 2);

	ListNode* cur = res;
	while (cur != nullptr)
	{
		cout << cur->val << '\t';
		cur = cur->next;
	}
	
}