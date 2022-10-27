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
// DP[i][j] represents whether s[0:i] is matching with p[0:j];
// Generic case:
// if p[j] == '*'--> DP[i][j] = DP[i][j-1], DP[i][j] = DP[i-1][j]
// else
//      if s[i] == p[j] --> DP[i][j] = DP[i-1][j-1]
//      if p[j] == '?' --> DP[i][j] = DP[i-1][j-1]

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> DP(m+1, vector<bool>(n+1, false));
        
        // when s and p are both empty
        DP[0][0] = true;

        // when s is empty --> handle the case when p contains '*'
        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*')
                DP[0][i] = DP[0][i - 1];
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // Don't forget that i and j are from 1, not zero.
                if (p[j - 1] == '*')
                    // Recall * can match any characters or empty
                    DP[i][j] = DP[i][j - 1] || DP[i - 1][j];
                else
                {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                        DP[i][j] = DP[i - 1][j - 1];
                    else
                        DP[i][j] = false;
                }
            }
        }
        return DP[m][n];
    }
};


int main()
{
    string s = "abefcdgiescdfimde", p = "ab*cd?i*de";

    Solution sol;

    if (sol.isMatch(s, p))
        cout << "MATCH\n";
    else
        cout << "No\n";
}