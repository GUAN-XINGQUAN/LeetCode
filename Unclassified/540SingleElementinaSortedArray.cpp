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
// #include "listNodeVisualization.h"

using namespace std;

// two pointers
// time complexity: O(N)
// space complexity: O(1)
class Solution1 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return nums[0];

        int slow = 0, fast = 1;
        while (fast < nums.size())
        {
            if (nums[slow] == nums[fast])
            {
                slow = slow + 2;
                fast = fast + 2;
            }
            else
                return nums[slow];
        }
        return nums[slow];
    }
};

// optimized approach: binary search
// time complexity O(log N)
// space complexity O(1)
class Solution2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size();
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            int next = (mid % 2 == 0) ? mid + 1 : mid - 1;

            if (nums[mid] == nums[next])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};


int main()
{
    Solution sol;

}