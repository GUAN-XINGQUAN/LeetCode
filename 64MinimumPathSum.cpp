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
// DP[i][j] represents the minimum summation at grid[i][j]
// DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
// Be cautious with corner case
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> DP(m, vector<int>(n, 0));
        DP[0][0] = grid[0][0];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                    DP[i][j] = DP[i][j-1] + grid[i][j];
                else if (j == 0)
                    DP[i][j] = DP[i-1][j] + grid[i][j];
                else
                    DP[i][j] = min(DP[i - 1][j], DP[i][j - 1]) + grid[i][j];
            }
        }
        return DP[m-1][n-1];
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1 }
    };

    Solution sol;

    int res = sol.minPathSum(grid);

    cout << res << endl;
}