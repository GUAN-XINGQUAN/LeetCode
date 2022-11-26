/*

*/

// brute force solution
// time O(n)
// space O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            m = min(m, nums[i]);
        }
        return m;
    }
};


// Binary search 
// time O(log n)
// space O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        if (nums.front() < nums.back())
            return nums.front();
        
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums.front())
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};