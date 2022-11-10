/*

idea:
    x can only be between 0 and nums.size

    sort the array
    for each x in [0, nums.size]
        find the number of elements >= x in the array
        if number == x:
            return x;

*/

// time O(n log n)
// space O(1)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = 0;
        for (; x <= nums.size(); x++)
        {
            int num = getNotLessThan(nums, x);
            if (num == x)
                return x;
        }
        return -1;
    }
    
    int getNotLessThan(vector<int>& nums, int x)
    {
        if (x < nums.front())
            return nums.size();
        if (x > nums.back())
            return 0;
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == x)
                right = mid;
            else if (nums[mid] < x)
                left = mid + 1;
            else
                right = mid;                
        }
        return nums.size() - left;
    }   
};