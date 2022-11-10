/*
idea:
    for each element in the 1st arry: find the last element in 2nd array that >= the current element in the 1st array
    both arries are sorted so we could use binary search
*/


// brute force solution
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDis = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = i; j < nums2.size(); j++)
            {
                if (nums1[i] <= nums2[j] && j - i > maxDis)
                    maxDis = j - i;
            }
        }
        return maxDis;
    }
};


// binary search
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDis = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int j = getLastIndex(nums2, i, nums1[i]);
            maxDis = max(j-i, maxDis);
        }
        return maxDis;
    }
    
    int getLastIndex(vector<int>& nums2, int left, int target)
    {
        int right = nums2.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2; 
            if (nums2[mid] == target)
                left = mid + 1;
            else if (nums2[mid] > target)
                left = mid + 1;
            else
                right = mid;
        }
        return left - 1 >= 0 ? left - 1 : -1;
    }
};

