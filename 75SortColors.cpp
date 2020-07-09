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

// Two passes: O(N)
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int color = nums[i];
            ++counts[color];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (counts[0] > 0)
            {
                nums[i] = 0;
                --counts[0];
            }
            else if (counts[1] > 0)
            {
                nums[i] = 1;
                --counts[1];
            }
            else
                nums[i] = 2;
        }
    }
};


// One pass: O(N)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i <= right; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[left]);
                left++;
            }
            else if (nums[i] == 1)
                continue;
            else
            {
                swap(nums[i], nums[right]);
                right--;
            }
        }
    }
};

int main()
{
    vector<int> colors = { 2, 0, 1};
    Solution sol;

    sol.sortColors(colors);
    for (int i = 0; i < colors.size(); i++)
        cout << colors[i] << '\t';
}