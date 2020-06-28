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

// O(N) ==> two pointers semi-linear scan the whole array (Not recommended because weird coding style)
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int left = 0, right = 0, sum = 0, result = nums.size() + 1;
        while (right < nums.size())
        {
            while (sum < s && right < nums.size())
            {
                sum += nums[right];
                right++;
            }
            while (sum >= s)
            {
                result = min(result, right - left);
                sum -= nums[left];
                left++;
            }
        }
        if (result > nums.size())
            return 0;
        else
            return result;
    }
};

// O(N) ==> semi-linear scan with clear coding style (recommended)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = INT_MAX, left = 0, sum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (left <= right && sum >= s)
            {
                length = min(length, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (length > nums.size())
            return 0;
        else
            return length;
    }
};

int main()
{
    vector<int> nums = { 2,3,1,2,4,3 };
    int s = 7;

    Solution sol;
    int res = sol.minSubArrayLen(s, nums);

    cout << res << endl;
}