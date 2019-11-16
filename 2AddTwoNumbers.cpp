#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}  // Constructor
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode* l1, ListNode *l2)
	{
		ListNode* tempResult = new ListNode(0); // dummy node
		ListNode* curPtr = tempResult;  // current pointer
		int digitInt = 0;
		while (l1 != nullptr || l2 != nullptr)
		{
			int val1, val2;
			if (l1 == nullptr)
				val1 = 0;
			else
			{
				val1 = l1->val;
				l1 = l1->next;
			}
			if (l2 == nullptr)
				val2 = 0;
			else
			{
				val2 = l2->val;
				l2 = l2->next;
			}
			int remainder = (val1 + val2 + digitInt) % 10;
			digitInt = (val1 + val2 + digitInt) / 10;
			
			curPtr->next = new ListNode(remainder);
			curPtr = curPtr->next;
		}
		if (digitInt != 0)
			curPtr->next = new ListNode(1);
		ListNode* result = tempResult->next;
		delete tempResult;
		return result;
	}
};


int main()
{
	// First linked list
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	// Second linked list
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	// Call function
	Solution sol;
	ListNode* result = sol.addTwoNumbers(l1, l2);

	// Display the result to verify
	ListNode* curPtr = result;
	while (curPtr != nullptr)
	{
		cout << curPtr->val << '\t';
		curPtr = curPtr->next;
	}
}