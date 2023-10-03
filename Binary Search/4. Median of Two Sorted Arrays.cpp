/*
Approach #1:
1. Save two arrays into one single array.
2. Sort this single array and get the median.

Approach #2:
Let's look at an example:
arr1:
    1   3 |  5   7  9
arr2:
    2   4 |  6   8  

We try to figure out a cut at arr1 and a cut at arr2 such that the cut tells us where the median could be. Cut1 (in arr1) and Cut2 (in arr2) shall satisfy the following conditions:
(1) number of elements at left of Cut1 and Cut2 = (n1 + n2) / 2
(2) arr1[left] <= arr2[left] AND arr2[left] <= arr1[left] where left denotes the element at left side of the cut.

To find the Cut1 and Cut2, we can use binary search.
We just need to find Cut1 because Cut2 can be determined from Cut1 (see conditions (1) listed above).

Another issue to consider is that, what if arr1 is longer than arr2? think about an extreme case where arr1 length is 100 but arr2 is 0?
To address this issue, we just need to ensure that arr1 is always the shorter one array and then we can focus on finding Cut1 (in arr1).
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ensure nums1 is always the shorter array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        // binary search on nums1
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        while (left <= right)
        {
            // find cut in nums1
            int cut1 = left + (right - left) / 2;
            // find cut in nums2
            int cut2 = (m + n) / 2 - cut1;
            // find left and right sides of cut1: do not forget index is out of bound issue
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int right1 = cut1 == m ? INT_MAX : nums1[cut1];
            // find left and right sides of cut2: do not forget index is out of bound issue
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int right2 = cut2 == n ? INT_MAX : nums2[cut2];
            // if the cut satifies the condition
            if (left1 <= right2 && left2 <= right1)
            {
                // even number of elements: average of middle two
                if ((m + n) % 2 == 0)
                    return static_cast<double>((max(left1, left2)*1.0 + min(right1, right2)*1.0) / 2.0);
                // odd number of elements: the very middle one
                else
                    return static_cast<double>(min(right1, right2));
            }
            else if (left1 > right2)
                right = cut1 - 1;
            else
                left = cut1 + 1;
        }
        return -1.0;
    }
};