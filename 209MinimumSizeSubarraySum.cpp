#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorCharVisualization.h"

using namespace std;

// O(N) solution:
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return (nums[0] >= s) ? 1 : 0;
        int left = 0, sum = 0, length = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                length = min(length, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (length == INT_MAX)
            return 0;
        else
            return length;
    }
};

// Follow up: O(N log N) solution
// Use binary search with one additional vector.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        // Create a new vector
        vector<int> sums(nums.size() + 1, 0);

        for (int i = 1; i < sums.size(); i++)
            sums[i] = nums[i-1] + sums[i - 1];

        int length = INT_MAX;
        for (int i = 0; i < sums.size(); i++)
        {
            int index = binarySearch(sums[i] + s, sums);
            if (index != -1)
                length = min(length, index - i);
        }
        if (length > nums.size())
            return 0;
        else
            return length;
    }

    int binarySearch(int target, vector<int>& sums)
    {
        int left = 0, right = sums.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (sums[mid] < target)
                left = mid;
            else
                right = mid;
        }
        
        if (right < left)
            return -1;
        if (sums[left] >= target)
            return left;
        else if (sums[right] >= target)
            return right;
        else
            return -1;

    }
};

int main()
{
    vector<int> vec = { 2,3,1,2,4,3 };
    int s = 7;

    Solution sol;
    cout << sol.minSubArrayLen(s, vec);

}