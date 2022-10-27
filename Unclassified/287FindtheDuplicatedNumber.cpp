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

// Time complexity < O(N^2)
// Space complexity O(1)
// ==> binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Only one duplicate number ==> nums cannot be empty and have at least two
        // elements
        int left = 1, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = countNumberLessThanMid(nums, mid);
            if (count <= mid)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    int countNumberLessThanMid(vector<int>& nums, int mid)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
                count++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = { 1, 1, 1, 1, 2};

    Solution sol;
    
    int res = sol.findDuplicate(nums);

    cout << res << endl;
}