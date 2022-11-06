/*

search window: [left, right] and termination condition left <= right

if directly find target --> return the index

otherwise

once terminate: left = right + 1 --> nums[right] < target < nums[left] --> return left

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};



