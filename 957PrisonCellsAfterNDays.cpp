#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// brute force (space limit exceeds)
class Solution1 {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int len = cells.size();
        vector<vector<int>> dp(N+1, vector<int>(len, 0));
        for (int i = 0; i < len; i++)
            dp[0][i] = cells[i];
        int count = 1;
        while (count <= N)
        {
            for (int i = 1; i < len - 1; i++)
            {
                if (dp[count-1][i - 1] == dp[count-1][i + 1])
                    dp[count][i] = 1;
            }
            count++;
        }
        return dp.back();
    }
};


// optimized dynamic programing with rolling array (time limit exceeds)
class Solution2 {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0)
            return cells;
        int len = cells.size();
        int count = 1;
        vector<vector<int>> dp (2, vector<int>(len, 0));
        for (int i = 0; i < len; i++)
            dp[0][i] = cells[i];
        while (count <= N)
        {
            int row = count % 2;
            for (int i = 1; i < len - 1; i++)
            {
                if (dp[1 - row][i - 1] == dp[1 - row][i + 1])
                    dp[row][i] = 1;
                else
                    dp[row][i] = 0;
            }
            dp[row][0] = dp[row][len - 1] = 0;
            count++;
        }
        return dp[N%2];
    }
};


// find the loop
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> state;
        bool hasCycle = false;
        int len = 0;
        for (int i = 0; i < N; i++)
        {
            vector<int> nextState = nextDayState(cells);
            if (hasTarget(state, nextState))
            {
                hasCycle = true;
                break;
            }
            state.push_back(nextState);
            len++;
            cells = nextState;
        }

        if (hasCycle)
            return prisonAfterNDays(cells, N % len);
        return cells;

    }
    vector<int> nextDayState(vector<int> previousCells)
    {
        vector<int> res(previousCells.size(), 0);
        for (int i = 1; i < previousCells.size() - 1; i++)
        {
            if (previousCells[i - 1] == previousCells[i + 1])
                res[i] = 1;
        }
        return res;
    }

    bool hasTarget(vector<vector<int>> matrix, vector<int> target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i] == target)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> cells = { 0,1,0,1,1,0,0,1};
    int N = 1000;

    vector<int> res = sol.prisonAfterNDays(cells, N);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}