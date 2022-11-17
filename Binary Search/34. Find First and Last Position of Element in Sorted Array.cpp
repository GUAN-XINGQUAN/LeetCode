/*

idea:
    use binary search twice to determine the lower and upper bounds respectively.

    when implementing the codes, combine the lower and upper bound functions into one single function by introducing a boolean variable.

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftMost = searchIndex(nums, target, true);
        int rightMost = searchIndex(nums, target, false);
        return vector<int> {leftMost, rightMost};
    }
    
    int searchIndex(vector<int>& sortedNums, int target, bool isLowerBound)
    {
        int left = 0, right = sortedNums.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (sortedNums[mid] == target)
            {
                if (isLowerBound)
                {
                    if (mid == left || sortedNums[mid-1] < target)
                        return mid;
                    right = mid - 1;
                }
                else
                {
                    if (mid == right || sortedNums[mid+1] > target)
                        return mid;
                    left = mid + 1;
                }
            }
            else if (sortedNums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
