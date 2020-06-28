#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorIntVisualization.h"

using namespace std;

// vector has no dupilicates.
// Binary search algorithm.
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] <= nums[right])
                right = middle;
            else
                left = middle;
        }
        return nums[left] < nums[right] ? nums[left] : nums[right];
    }
};

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    Solution sol;
    cout << sol.findMin(nums) << endl;
}