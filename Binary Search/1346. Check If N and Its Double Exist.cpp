/*


*/

// brute force
// time O(n^2)
// space O(1)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                if (i == j)
                    continue;
                if (arr[i] == 2 * arr[j])
                    return true;
            }
        }
        return false;
    }
};

// binary search
// space O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // valid input
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> nums = {arr.begin(), arr.begin()+i};
            if (doubleExists(nums, arr[i]))
                return true;
        }
        return false;
    }
    
    
    bool doubleExists(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target > 0)
            {
                if (2 * nums[mid] == target)
                    return true;
                else if (2 * nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if (2 * target == nums[mid])
                    return true;
                else if (2 * target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};