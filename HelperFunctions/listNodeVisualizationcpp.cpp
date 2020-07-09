#include <iostream>

#include "listNodeVisualization.h"

using namespace std;

void listNodeVisualization(ListNode* node)
{
	if (node == nullptr)
		cout << "Empty list\n";

	while (node != nullptr)
	{
		cout << node->val << '\t';
		node = node->next;
	}
}