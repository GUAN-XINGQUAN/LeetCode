#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// Solution I: use STL
// Time complexity O(N)
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> num2Count;
        for (int i = 0; i < nums2.size(); i++)
            ++num2Count[nums2[i]];
        for (int i = 0; i < nums1.size(); i++)
        {
            if (num2Count[nums1[i]] > 0)
            {
                res.push_back(nums1[i]);
                --num2Count[nums1[i]];
            }
        }
        return res;
    }
};

// Solution II: use two pointers
// Time complexity: O(N log N)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums1 = { 1, 2, 2, 1 }, nums2 = { 2,2 };
    Solution sol;
    vector<int> res = sol.intersect(nums1, nums2);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}