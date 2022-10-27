#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "NestedVectorCharVisualization.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int rowNum = grid.size(), colNum = grid[0].size();
        int count = 0;
        vector<vector<bool>> visit(rowNum, vector<bool>(colNum));
        for (int i = 0; i < rowNum; i++)
        {
            for (int j = 0; j < colNum; j++)
                visit[i][j] = false;
        }
        for (int i = 0; i < rowNum; i++)
        {
            for (int j = 0; j < colNum; j++)
            {
                if (grid[i][j] == '0' || visit[i][j])
                    continue;
                count++;
                queue<int> location({ i * colNum + j });

                // BFS
                while (!location.empty())
                {
                    int loc = location.front();
                    location.pop();
                    int row = loc / colNum, col = loc % colNum;
                    if (row > 0 && !visit[row - 1][col] && grid[row-1][col] != '0')
                    {
                        visit[row - 1][col] = true;
                        location.push((row-1)*colNum+col);
                    }
                    if (row < rowNum-1 && !visit[row + 1][col] && grid[row + 1][col] != '0')
                    {
                        visit[row + 1][col] = true;
                        location.push((row + 1) * colNum + col);
                    }
                    if (col > 0 && !visit[row][col-1] && grid[row][col-1] != '0')
                    {
                        visit[row][col-1] = true;
                        location.push(row * colNum + col - 1);
                    }
                    if (col < colNum-1 && !visit[row][col + 1] && grid[row][col+1] != '0')
                    {
                        visit[row][col + 1] = true;
                        location.push(row*colNum+col+1);
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<char>> grid1 =
    { {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'} };

    vector<vector<char>> grid2 =
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    int res1 = sol.numIslands(grid1);
    int res2 = sol.numIslands(grid2);
    // nestedVectorCharVisualization(grid);

    cout << res1 << endl;
    cout << res2 << endl;
}