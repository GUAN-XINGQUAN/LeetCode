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

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[right])
            {
                if (nums[left] <= target && nums[mid] >= target)
                    right = mid;
                else
                    left = mid;
            }
            else if (nums[mid] < nums[right])
            {
                if (nums[mid] <= target && nums[right] >= target)
                    left = mid;
                else
                    right = mid;
            }
            else
                right--;
        }
        if (left > right)
            return false;
        else if (nums[left] == target)
            return true;
        else if (nums[right] == target)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<int> vec = { 1, 1, 1, 1, 0, 1, 1, 1 };
    int target = 0;

    Solution sol;

    bool res = sol.search(vec, target);

    if (res)
        cout << "Yes\n";
    else
        cout << "No\n";
}