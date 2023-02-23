class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n =t.size();
        vector<vector<bool>> dp (m+1, vector<bool>(n+1, false));
        for (int i = 0; i <= m; i++)
            dp[i][0] = false;
        for (int j = 0; j <= n; j++)
            dp[0][j] = true;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    dp[i][j] = false;
                dp[i][j] = (dp[i-1][j-1] && s[i-1]==t[j-1]) || dp[i][j-1];
            }
        }
        return dp.back().back();
    }   
};


/*
    0   1   2   3   4
    a   f   b   f   c

    0   1   2
    a   b   c

    0   1   2   3   4
0   T   T   T   T   T
1   F   F   T   T   T
2   F   F   F   F   T


    0   1
0   T   T
1   F   F


dp[i][j]:

    dp[0][0] = s[0] == t[0];
    dp[0][j] = dp[0][j-1]
    dp[i][0] = false

    s[0:i] is a subsequence of t[0:j]

    if i > j:
        false

    dp[i][j] = (dp[i-1][j-1] && s[i]==t[j]) || dp[i][j-1]
    

*/