/*

*/


// brute force
// time O(m*n)
// space O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // valid input
        int s = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] < 0)
                    s++;
            }
        }
        return s;
    }
};


// binary search
// time O(m * log n)
// space O(n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int s = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int index = lessThanZero(grid[i]);
            if (index != -1)
                s += grid[i].size() - index;
        }
        return s;
    }
    
    int lessThanZero(vector<int>& nums)
    {
        if (nums.front() < 0)
            return 0;
        if (nums.back() >= 0)
            return -1;
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == 0)
                left = mid + 1;
            else if (nums[mid] < 0)
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left] < 0 ? left : -1;
    }
};