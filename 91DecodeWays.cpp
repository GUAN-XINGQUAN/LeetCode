#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // edge case
        if (s.empty() || s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;

        int n = s.size();
        vector<int> dp(n + 1, 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            int index = i - 1;
            if (!isValid(s[index]) && !isValid(s[index - 1], s[index]))
            {
                dp[i] = 0;
                return 0;
            }
            if (isValid(s[index]) && isValid(s[index - 1], s[index]))
                dp[i] = dp[i - 1] + dp[i - 2];
            else if (isValid(s[index]))
                dp[i] = dp[i - 1];
            else if (isValid(s[index - 1], s[index]))
                dp[i] = dp[i - 2];
        }
        return dp.back();
    }
    // function overload
    bool isValid(char ch)
    {
        if (ch != '0')
            return true;
        return false;
    }
    bool isValid(char ch1, char ch2)
    {
        int num = (ch1 - '0') * 10 + (ch2 - '0') * 1;
        if (num <= 26 && num >= 10)
            return true;
        return false;
    }
};


int main()
{
    Solution sol;

    string s = "102213";

    int res = sol.numDecodings(s);

    cout << res << endl;
}