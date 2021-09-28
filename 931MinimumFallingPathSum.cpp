class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp (m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 1st row
                if (i == 0)
                    dp[i][j] = matrix[i][j];
                // rest rows
                else
                {
                    // leftmost 
                    if (j == 0)
                        dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                    // rightmost
                    else if (j == n-1)
                        dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];
                    // middle case
                    else
                        dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + matrix[i][j];
                }
            }
        }
        int mn = INT_MAX;
        for (int j = 0; j < m; j++)
            mn = min(dp.back()[j], mn);
        return mn;
    }
};