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
// DP[i][j]: longest palindrome from s[i] to s[j]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty())
            return 0;

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >=0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    Solution sol;

    string s = "bbbba";

    int res = sol.longestPalindromeSubseq(s);

    cout << res << endl;
    
}