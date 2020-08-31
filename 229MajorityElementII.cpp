#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int a = INT_MIN, b = INT_MIN, countA = 0, countB = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == a)
                countA++;
            else if (nums[i] == b)
                countB++;
            else if (countA == 0)
            {
                a = nums[i];
                countA++;
            }
            else if (countB == 0)
            {
                b = nums[i];
                countB++;
            }
            else
            {
                countA--;
                countB--;
            }
        }


        countA = countB = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == a)
                countA++;
            else if (nums[i] == b)
                countB++;
        }

        int n = nums.size();
        if (countA > n / 3)
            res.push_back(a);
        if (countB > n / 3)
            res.push_back(b);

        return res;
    }
};


int main()
{
    Solution sol;
}