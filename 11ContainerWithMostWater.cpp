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

using namespace std;

// time complexity O(N)
// Two pointers moving towards each other
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};

int main()
{
    vector<int> heights = { 1,8,6,2,5,4,8,3,7 };

    Solution sol;

    int res = sol.maxArea(heights);

    cout << res << endl;
}