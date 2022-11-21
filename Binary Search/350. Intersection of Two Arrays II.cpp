/*

*/

// hash table + linear scan
// m = nums1.size(), n = nums2.size()
// time O(m + n)
// space O(m)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // save nums1 to hash table
        unordered_map<int, int> num2Count;
        for (int i = 0; i < nums1.size(); i++)
            num2Count[nums1[i]] += 1;
        // trace nums2 to retrieve the overlaps
        vector<int> overlap;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (num2Count.count(nums2[i]) > 0 && num2Count[nums2[i]] > 0)
            {    
                overlap.push_back(nums2[i]);
                num2Count[nums2[i]] -= 1;
            }
        }
        return overlap;
    }
};


// optimized hash table + linear scan
// m = nums1.size(), n = nums2.size()
// time O(m + n)
// space O(min(m, n))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // ensure that we always use hash table to track the shorter array to save space
        if (nums1.size() > nums2.size())
            return helper(nums2, nums1);
        return helper(nums1, nums2);         
    }
    
    vector<int> helper(vector<int>& nums1, vector<int>& nums2)
    {
        // save nums1 to hash table
        unordered_map<int, int> num2Count;
        for (int i = 0; i < nums1.size(); i++)
            num2Count[nums1[i]] += 1;
        // trace nums2 to retrieve the overlaps
        vector<int> overlap;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (num2Count.count(nums2[i]) > 0 && num2Count[nums2[i]] > 0)
            {    
                overlap.push_back(nums2[i]);
                num2Count[nums2[i]] -= 1;
            }
        }
        return overlap;
    }
};


// sort + two pointers
// m = nums1.size(), n = nums2.size()
// time O(m log m + n log n + max(m, n)) = O(m log m + n log n)
// space O(log m + log n) required for sorting
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if (nums1.size() > nums2.size())
            return helper(nums1, nums2);
        return helper(nums2, nums1);
    }
    
    vector<int> helper(vector<int>& nums1, vector<int>& nums2) 
    {
        // nums1 is always longer than nums2
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                nums1[k] = nums1[i];
                i++, j++, k++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return vector<int> {nums1.begin(), nums1.begin()+k};
    }
};


/*
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
    I will use the last approach. When the array is already sorted, the time complexity is linear time O(max(m, n)) and the space complexity is contant space O(1).

What if nums1's size is small compared to nums2's size? Which algorithm is better?
    I will use hashmap for nums1 to reduce the space complexity (approach #1).

What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
    If nums1 fits into the memory, just use the 1st approach by loading the nums2 portion by portion such that each portion fits into the memory.
    If none of these two arrays fit into the memory, I will still use approach 1 but each time, I will only process a subarray of nums1 and nums2.

*/