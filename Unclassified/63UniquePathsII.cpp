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

// Dynamic programing:
// DP[i][j] represents the number of uniqie path to grid[i][j]
// DP[i][j] = DP[i-1][j] + DP[i][j-1]
// Be cautious with the corner case --> make DP with a size of (m+1)*(n+1)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // edge case
        // no grid world at all or beginning point is an obstacle
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
            return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> DP(m + 1, vector<int>(n + 1, 0));
        DP[0][1] = 1;
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)
                    continue;
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }
        return DP[m][n];
    }
};

int main()
{
    vector<vector<int>> gridWord = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    Solution sol;
    int res = sol.uniquePathsWithObstacles(gridWord);

    cout << res << endl;
}