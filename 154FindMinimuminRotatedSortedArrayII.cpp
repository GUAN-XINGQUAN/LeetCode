#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

// User defined function to visualize 2D array.
#include "NestedVectorIntVisualization.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // Unnecessary edge case
        if (nums.empty())
            return INT_MIN;


        int left = 0, right = nums.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] == nums[right])
                right--;
            else
                left = mid;
        }

        if (nums[left] <= nums[right])
            return nums[left];
        else
            return nums[right];
    }
};

int main()
{
    vector<int> vec1 = { 1, 2, 3 };
    vector<int> vec2 = { 3,1,2,3 };
    vector<int> vec3 = { 0, 0, 0, 0 };
    vector<int> vec4 = { 1,2,3,1,1,1 };

    Solution sol;
    assert(sol.findMin(vec1) == 1);
    assert(sol.findMin(vec2) == 1);
    assert(sol.findMin(vec3) == 0);
    assert(sol.findMin(vec4) == 1);

    cout << "All cases passed!\n";
}