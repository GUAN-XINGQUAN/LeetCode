#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;
        for (; right < nums.size(); right++)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};


int main()
{
    vector<int> nums = {3,2,2,3};
    Solution sol;
    int res = sol.removeElement(nums, 2);
    cout << res << endl;
    
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << '\t';
}