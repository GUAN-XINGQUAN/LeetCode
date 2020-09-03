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
    int heightChecker(vector<int>& heights) {
        vector<int> sortedH{ heights.begin(), heights.end() };
        sort(sortedH.begin(), sortedH.end());
        int res = 0;
        for (int i = 0; i < sortedH.size(); i++)
        {
            if (heights[i] != sortedH[i])
                res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = { 1, 2, 3, 1 };

    int res = sol.rob(nums);

    cout << res << endl;
    
}