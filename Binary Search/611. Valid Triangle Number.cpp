// brute force solution
// to create a triangle, the following three conditions should be satifised at t he same time:
// nums[i] + nums[j] > nums[k]
// nums[j] + nums[k] > nums[i] 
// nums[k] + nums[i] > nums[j]
// time O(n^3)
// space O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                for (int k = j+1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] > nums[k] && nums[j] + nums[k] > nums[i] && nums[k] + nums[i] > nums[j])
                        result++;
                }
            }
        }
        return result;
    }
};


// optimized brute force solution -- > binary search
// In the inner most loop, we can actually use binary search to find the largest element that is less than sum of first two numbers
// Be sure to sort the array to use binary search
// time O(n^2 * log n)
// space O(log n) depending on sorting algorithm
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                int index = findLargestBelowTarget(nums, j+1, nums.size(), nums[i]+nums[j]);
                if (index == -1)
                    continue;
                int ct = index - j;
                result += ct;
            }
        }
        return result;
    }
    
    int findLargestBelowTarget(vector<int> nums, int left, int right, int target)
    {
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left - 1 >= 0 ? left - 1 : -1;
    }
};

// More optimized solution:
// once we sort the array, we just need to find nums[i] + nums[j] > nums[k]
// we can firstly fix i and j, then find the minimum k to satisfy nums[i] + nums[j] < nums[k]
// then the number of combiantion would be k - j + 1
// when moving the index j to j + 1, we don't have to re-start k from j + 1. Instead, we just continue the k from the last stopping point.
// for example, this is the sorted array:
// [a, b, x1, x2, x3, x4, c, d, e, f]
// when nums[i] = a and nums[j] = b, assume that we find c is the smallest element that satisfy a > a + b
// then the possible combination would be (a, b, x1), (a, b, x2), (a, b, x3), (a, b, x4), which should be 4
// going to the next iteration:
//  when nums[i] = a and nums[j] = x1, we don't have to search k from x2. Instead, we just continue search k from c.
// this is because in the last iteration: we find a + b > c
// therefore, in this round, a + x1 is surely greater than c because x1 >= b. In other words, we don't have to wate time in searching x1, x2, ..., c for the nums[k].
// by leveraging such characteristic, we can reduce the time complexity to O(n^2) becasue searching index j and k together become O(n).
// time O(n^2)
// space O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size()-2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < nums.size()-1; j++)
            {
                while (k < nums.size() && nums[i] + nums[j] > nums[k])
                    k++;
                result += k - j - 1;
            }
        }
        return result;
    }
};
