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

// memoriation
class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet{ wordDict.begin(), wordDict.end() };
        vector<int> memo(s.size(), -1);
        return helper(s, wordSet, 0, memo);
    }
    bool helper(string s, unordered_set<string>& wordSet, int start, vector<int>& memo)
    {
        if (start >= s.size())
            return true;
        if (memo[start] != -1)
            return memo[start];
        for (int i = start + 1; i <= s.size(); i++)
        {
            if (wordSet.count(s.substr(start, i - start)) != 0 && helper(s, wordSet, i, memo))
            {
                memo[start] = 1;
                return true;
            }
        }
        return false;
    }
};

// dynamic programing
// dp[i]: s[0:i] could be broke into words in dict or not
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet{ wordDict.begin(), wordDict.end() };
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && (wordSet.count(s.substr(j, i - j)) != 0))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

int main()
{
	Solution sol;

    string s = "leetcode";

    vector<string> wordDict = { "leet", "code" };

    if (sol.wordBreak(s, wordDict))
        cout << "YES\n";
    else
        cout << "No\n";
}