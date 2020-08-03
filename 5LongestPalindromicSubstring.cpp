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

// Emurate: time O(N^2)
class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int start = 0, maxLength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            findPalindrome(s, i, i, start, maxLength);
            findPalindrome(s, i, i + 1, start, maxLength);
        }
        return s.substr(start, maxLength);
    }
    void findPalindrome(string s, int left, int right, int& start, int& maxLength)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (maxLength < right - left - 1)
        {
            start = left + 1;
            maxLength = right - left - 1;
        }
    }
};


// Dynamic programing:
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int n = s.size(), left = 0, maxLength = 1;
        vector<vector<bool>> DP (n, vector<bool> (n, false));
        for (int i = 0; i < n; i++)
        {
            DP[i][i] = 1;
            for (int j = 0; j < i; j++)
            {
                    DP[j][i] = s[i] == s[j] && (i - j < 2 || DP[j + 1][i - 1]);
                if (DP[j][i] == true && maxLength < i - j + 1)
                {
                    maxLength = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, maxLength);
    }
};

int main()
{
    string s = "aba";

    Solution sol;

    string res = sol.longestPalindrome(s);

    cout << res << endl;
}