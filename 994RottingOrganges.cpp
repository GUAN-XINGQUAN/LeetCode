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
#include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // edge case
        if (grid.empty() || grid[0].empty())
            return 0;

        int row = grid.size(), col = grid[0].size();
        int flag = 0;
        queue<int> locQueue;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                    locQueue.push(i * col + j);
                if (grid[i][j] == 1)
                    flag++;
            }
        }

        // No fresh organge
        if (flag == 0)
            return 0;
        // No rotten orange
        if (locQueue.empty())
            return -1;

        int res = 0;
        while (!locQueue.empty())
        {
            res++;
            for (int k = locQueue.size(); k > 0; k--)
            {
                int temp = locQueue.front();
                locQueue.pop();
                int x = temp / col, y = temp % col;
                if (x > 0 && grid[x - 1][y] == 1)
                {
                    locQueue.push(temp - col);
                    grid[x-1][y] = 2;
                }
                if (x < row - 1 && grid[x + 1][y] == 1)
                {
                    locQueue.push(temp + col);
                    grid[x+1][y] = 2;
                }
                if (y > 0 && grid[x][y - 1] == 1)
                {
                    locQueue.push(temp - 1);
                    grid[x][y - 1] = 2;
                }
                if (y < col - 1 && grid[x][y + 1] == 1)
                {
                    locQueue.push(temp + 1);
                    grid[x][y + 1] = 2;
                }
            }
        }
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return res - 1;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid1 = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };

    vector<vector<int>> grid2 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    vector<vector<int>> grid3 = { {0, 2} };

    vector<vector<int>> grid4 = { {1}, {2}, {2} };

    //int res = sol.orangesRotting(grid1);
    int res = sol.orangesRotting(grid2);
    //int res = sol.orangesRotting(grid3);
    //int res = sol.orangesRotting(grid4);

    cout << res << endl;
}