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

// DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = 0;
        vector<bool> visit(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visit[i])
                continue;
            DFSHelper(M, i, visit);
            res++;
        }
        return res;
    }
    void DFSHelper(vector<vector<int>>& M, int k, vector<bool>& visit)
    {
        visit[k] = true;
        for (int i = 0; i < M.size(); i++)
        {
            if (M[k][i] == 1 && !visit[i])
                DFSHelper(M, i, visit);
        }
    }
};


int main()
{
    Solution sol;

    vector<vector<int>> M = { {1,1,0}, {1,1,0}, {0,0,1} };
    int res = sol.findCircleNum(M);
    cout << res << endl;
}