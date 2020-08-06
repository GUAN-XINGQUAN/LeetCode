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

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '0')
                dp[i] = 0;
            else
                dp[i] = dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6'))
                dp[i] = dp[i] + dp[i - 2];
        }
        return dp.back();
    }
};

int main()
{
    Solution sol;

    string s = "226";

    int res = sol.numDecodings(s);

    cout << res << endl;
    
}