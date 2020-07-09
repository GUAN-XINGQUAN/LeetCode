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
#include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // edge case
        if (nums.size() <= 2)
            return nums.size();
        // fast and slow pointers
        int count = 1, left = 0, right = 1;
        while (right < nums.size())
        {
            if (nums[right] == nums[left] && count == 0)
                right++;
            else
            {
                if (nums[right] == nums[left])
                    count--;
                else
                    count = 1;
                left++;
                nums[left] = nums[right];
                right++;
            }
        }
        return left+1;
    }
};

int main()
{
    vector<int> nums = { 1,1,1,2,3,3,3,3,4 };
    Solution sol;

    sol.removeDuplicates(nums);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << '\t';
}