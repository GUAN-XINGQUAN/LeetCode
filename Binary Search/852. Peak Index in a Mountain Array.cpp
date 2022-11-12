/*

if nums[mid] < nums[mid+1]: the peak must be located at the right side of mid, so left = mid + 1
else the peak must be at the left side of mid or it could be the mid itself. so right = mid

termination: left < right. right points to the peak element

*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid+1])
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};