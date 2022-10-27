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
#include "treeVisualizationinPreorder.h"
#include "listNodeVisualization.h"

using namespace std;

// Recursion
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            dp.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        int res = 0;
        if (i < 1)
            res = dp[j] - 0;
        else
            res = dp[j] - dp[i-1];
        return res;
    }
private:
    vector<int> dp;
};



int main()
{
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(0, 5);
    cout << param_1 << endl;
}