#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 1)
            return double(findKthElement(nums1, 0, nums2, 0, (m + n + 1) / 2));
        else
            return (findKthElement(nums1, 0, nums2, 0, (m+n+1)/2) + findKthElement(nums1, 0, nums2, 0, (m+n+2)/2)) / 2.0;
        
    }
    int findKthElement(vector<int>& nums1, int i, vector<int> nums2, int j, int k)
    {
        if (i >= nums1.size())
            return nums2[j + k - 1];
        if (j >= nums2.size())
            return nums1[i + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int medianVal1, medianVal2;
        if (i + k / 2 - 1 < nums1.size())
            medianVal1 = nums1[i + k / 2 - 1];
        else
            medianVal1 = INT_MAX;
        if (j + k / 2 - 1 < nums2.size())
            medianVal2 = nums2[j + k / 2 - 1];
        else
            medianVal2 = INT_MAX;
        if (medianVal1 < medianVal2)
            return findKthElement(nums1, i + k / 2, nums2, j, k-k/2);
        else
            return findKthElement(nums1, i, nums2, j + k / 2, k-k/2);
    }
};

int main()
{
    Solution sol;

    vector<int> vec1 = { 1, 3 };
    vector<int> vec2 = { 2 };

    double res = sol.findMedianSortedArrays(vec1, vec2);

    cout << res << endl;
}