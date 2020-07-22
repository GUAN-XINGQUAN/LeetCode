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
// #include "listNodeVisualization.h"

using namespace std;

// Brute force
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int longestStreak = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int currentNum = nums[i];
            int currentStreak = 1;

            while (isInArray(nums, currentNum))
            {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
        return longestStreak;
    }
    bool isInArray(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return true;
        }
        return false;
    }
};

// Sort and find: O(N log N)
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();

        sort(nums.begin(), nums.end());

        int longestStreak = 1, currentStreak = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                    currentStreak++;
                else
                {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }
        return max(longestStreak, currentStreak);
    }
};

// Use hash set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        int longestStreak = 0;
        unordered_set<int> numSet{ nums.begin(), nums.end() };
        for (int each : numSet)
        {
            if (numSet.count(each - 1) == 0)
            {
                int currentNum = each, currentStreak = 1;
                while (numSet.count(currentNum + 1) > 0)
                {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};


int main()
{
    vector<int> vec = { 100, 4, 200, 1, 3, 2 };
    Solution sol;
    int res = sol.longestConsecutive(vec);

    cout << res << endl;
}