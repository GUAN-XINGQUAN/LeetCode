#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorCharVisualization.h"

using namespace std;

// Sort algorithm (Not recommended since no real algorithm is involved).
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// Divide and conquer ==> quick sort using descending order.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int index = partition(nums, left, right);
            if (index == k - 1)
                return nums[index];
            if (index > k - 1)
                right = index-1;
            else
                left = index+1;
        }
        return -1;
    
    }
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[left];
        int start = left + 1, end = right;
        while (start <= end)
        {
            if (nums[start]<pivot && nums[end]>pivot)
            {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
            if (nums[start] >= pivot)
                start++;
            if (nums[end] <= pivot)
                end--;
        }
        swap(nums[left], nums[end]);
        return end;
    }
};


int main()
{
    vector<int> nums = { -1,2,0 };
    
    Solution sol;

    int res = sol.findKthLargest(nums, 2);
    cout << res << endl;

    //int res = sol.partition(nums, 0, 3);

    //for (int i = 0; i < nums.size(); i++)
    //    cout << nums[i] << '\t';
    //cout << endl;
}