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

// Brute force (not recommended) ==> linear scan
class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i <= nums.size() - 1; i++)
        {
            if (isPeak(nums, i))
                return i;
        }
        if (nums.empty())
            return -1;
        return nums.size()-1;
    }

    bool isPeak(vector<int>& nums, int index)
    {
        if (nums.empty())
            return false;
        if (nums.size() == 1)
            return true;
        if (index == 0)
        {
            if (nums[index] > nums[index + 1])
                return true;
        }
        else if (index == nums.size()-1)
        {
            if (nums[index] > nums[index - 1])
                return true;
        }
        else
        {
            if (nums[index] > nums[index - 1] && nums[index] > nums[index + 1])
                return true;
        }
        return false;
    }
};

// Binary search
// Please note that the peak element surely exist based on the problem statement.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return 0;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid;
        }
        return nums[left] > nums[right] ? left : right;
    }
};

int main()
{
    vector<int> nums = { 1, 2, 1, 2, 1 };
    Solution sol;
    int res = sol.findPeakElement(nums);

    cout << res;

}