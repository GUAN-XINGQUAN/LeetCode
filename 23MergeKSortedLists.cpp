#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// Method 1: Divde and Conquer
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if (n == 0)
			return nullptr;
		while (n > 1)
		{
			int k = (n + 1) / 2;
			for (int i = 0; i < n/2; i++)
			{
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1 != nullptr)
			cur->next = l1;
		if (l2 != nullptr)
			cur->next = l2;
		return dummy->next;
	}
};


// Main program to test
int main()
{
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(4);
	head1->next->next = new ListNode(5);

	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(3);
	head2->next->next = new ListNode(4);

	ListNode* head3 = new ListNode(2);
	head3->next = new ListNode(6);
	
	vector<ListNode*> vec = { head1, head2, head3 };
	Solution sol;
	ListNode* res = sol.mergeKLists(vec);
	cout << res->val;
}