#include <iostream>
#include <list>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(0); // dummy node
		ListNode* cur = res; // define a current pointer to loop over the node
		int remainder = 0;  // the variable deal with remainder of greater than 10
		while (l1 != nullptr || l2 != nullptr)
		{
			int val1, val2;
			if (l1 == nullptr)
				val1 = 0;
			else
				val1 = l1->val;
			if (l2 == nullptr)
				val2 = 0;
			else
				val2 = l2->val;
			int s = val1 + val2 + remainder;
			ListNode* ptr = new ListNode(s % 10);
			remainder = s / 10;
			cur->next = ptr;
			cur = cur->next;
			if (l1 != nullptr)
				l1 = l1->next;
			if (l2 != nullptr)
				l2 = l2->next;
		}
		if (remainder != 0)
			cur->next = new ListNode(1);
		ListNode* ans = res->next;
		delete res;  // delete the dummy node to avoid memory leak
		return ans;
	}
};

int main()
{
	ListNode* root1 = new ListNode(2);
	root1->next = new ListNode(4);
	root1->next->next = new ListNode(3);

	ListNode* root2 = new ListNode(5);
	root2->next = new ListNode(6);
	root2->next->next = new ListNode(4);

	Solution sol;

	ListNode* res = sol.addTwoNumbers(root1, root2);

	ListNode* cur = res;
	while (cur != nullptr)
	{
		cout << cur->val;
		cur = cur->next;
	}

	// Free up the dynamically allocated memory to avoid memory leak
	ListNode* cur1 = root1;
	while (cur1 != nullptr)
	{
		ListNode* temp = cur1->next;
		delete cur1;
		cur1 = temp;
	}

	ListNode* cur2 = root2;
	while (cur2 != nullptr)
	{
		ListNode* temp = cur2->next;
		delete cur2;
		cur2 = temp;
	}

	ListNode* cur3 = res;
	while (cur3 != nullptr)
	{
		ListNode* temp = cur3->next;
		delete cur3;
		cur3 = temp;
	}
}