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

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int res = 0, maxCount = 0, start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ++counts[s[i] - 'A'];
            maxCount = max(maxCount, counts[s[i] - 'A']);
            while (i - start + 1 - maxCount > k)
            {
                --counts[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};

int main()
{
    string s = "AABABBA";
    int k = 1;
    Solution sol;

    int res = sol.characterReplacement(s, k);

    cout << res << endl;
}