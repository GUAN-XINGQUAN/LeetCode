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

// Dynamic programing
// dp[i]: number of binary trees with i numbers
// dp[i] = sigma dp[i-1]dp[n-i+1]
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j]*dp[i - j - 1];
            }
        }
        return dp.back();
    }
};

int main()
{
	Solution sol;

    int i = 3;

    int res = sol.numTrees(i);

    cout << res << endl;
}