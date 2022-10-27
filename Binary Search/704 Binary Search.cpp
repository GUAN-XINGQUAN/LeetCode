/*
searching window [left, right] with both ends inclusive

termination condition: left <= right, which means the searching window looks like [right+1, right] with zero element

why left = mid + 1 and right = mid - 1:

we already searched the middle element and the next iteration should remove this middle element

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        return -1;
    }
};
