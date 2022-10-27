#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 3; i < n+1; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * (i-j), j*dp[i-j]));
            }
        }
        return dp.back();
    }
};


int main()
{
    Solution sol;

}