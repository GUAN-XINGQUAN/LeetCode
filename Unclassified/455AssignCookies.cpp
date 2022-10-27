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
#include "treeVisualizationinPreorder.h"
#include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0, count = 0;
        for (int i = 0; i < g.size(); i++)
        {
            while (count < s.size())
            {
                if (s[count] >= g[i])
                {
                    res++;
                    count++;
                    break;
                }
                count++;
            }
        }
        return res;
    }
};



int main()
{
    Solution sol;
    vector<int> g = { 1, 2, 3 };
    vector<int> s = { 1, 2 };
    int res = sol.findContentChildren(g, s);

    cout << res << endl;
}