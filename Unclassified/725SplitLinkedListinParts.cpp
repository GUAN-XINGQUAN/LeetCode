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

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = countListLength(root);
        int typicalSegement = len / k;
        vector<ListNode*> res;
        ListNode* cur = root;
        for (int i = 1; i <= k; i++)
        {
            // push the current head
            if (cur != nullptr)
                res.push_back(cur);
            else
                res.push_back({nullptr});

            // how many nodes in the current list
            int upper = (i <= len % k) ? typicalSegement + 1 : typicalSegement;
            
            for (int j = 1; j < upper; j++)
                cur = cur->next;

            if (cur != nullptr)
            {
                ListNode* temp = cur;
                cur = cur->next;
                temp->next = nullptr;
            }
        }
        return res;
    }
    int countListLength(ListNode* root)
    {
        int res = 0;
        while (root != nullptr)
        {
            res++;
            root = root->next;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    int res = sol.countListLength(head);
    cout << res << endl;
}