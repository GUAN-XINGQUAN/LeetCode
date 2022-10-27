#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
#include "listNodeVisualization.h"

using namespace std;

// two pointers
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ptrA = headA, * ptrB = headB;
        while (ptrA != ptrB)
        {
            if (ptrA == nullptr)
                ptrA = headB;
            else
                ptrA = ptrA->next;
            if (ptrB == nullptr)
                ptrB = headA;
            else
                ptrB = ptrB->next;
        }
        return ptrA;
    }
};

int main()
{
    Solution sol;

}