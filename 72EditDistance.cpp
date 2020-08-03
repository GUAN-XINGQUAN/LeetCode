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
// #include "listNodeVisualization.h"

using namespace std;

// Memorization approach
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int res = helper(word1, 0, word2, 0, memo);
        return res;
    }
    int helper(string word1, int i, string word2, int j, vector<vector<int>>& memo)
    {
        // need more insert operations
        if (i == word1.size())
            return int(word2.size() - j);
        // need more delete operations
        if (j == word2.size())
            return int(word1.size() - i);
        // memorization to avoid repeat computation
        if (memo[i][j] > 0)
            return memo[i][j];
        int res = 0;
        // two characters are equal
        if (word1[i] == word2[j])
            return helper(word1, i + 1, word2, j + 1, memo);
        else
        {
            // three different operations
            int insertCount = helper(word1, i, word2, j + 1, memo);
            int deleteCount = helper(word1, i + 1, word2, j, memo);
            int replaceCount = helper(word1, i + 1, word2, j + 1, memo);
            // get the minimum one from these three
            res = min(insertCount, min(deleteCount, replaceCount))+1;
        }
        memo[i][j] = res;
        return res;
    }
};


// Dynamic programing
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> DP(m+1, vector<int>(n+1, 0));
        DP[0][0] = 0;
        for (int j = 1; j <= n; j++)
            DP[0][j] = j;
        for (int i = 1; i <= m; i++)
            DP[i][0] = i;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    DP[i][j] = DP[i - 1][j - 1];
                else
                    DP[i][j] = min(DP[i - 1][j], min(DP[i][j - 1], DP[i - 1][j - 1]))+1;
            }
        }
        return DP.back().back();
    }
};


int main()
{
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    int res = sol.minDistance(word1, word2);

    cout << res << endl;
}