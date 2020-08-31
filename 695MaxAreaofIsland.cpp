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

// BFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // edge case
        if (grid.empty() || grid[0].empty())
            return 0;

        int res = 0;
        queue<int> locQueue;
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        // up, down, left, right
        vector<vector<int>> dirs = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

        // BFS
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // skip waters and visited spots
                if (grid[i][j] == 0 || visit[i][j])
                    continue;
                int currentCnt = 0;
                int loc = i * col + j;
                locQueue.push(loc);
                visit[i][j] = true;
                while (!locQueue.empty())
                {
                    int temp = locQueue.front();
                    locQueue.pop();
                    int x = temp / col, y = temp % col;
                    res = max(res, currentCnt++);
                    for (auto eachDir : dirs)
                    {
                        int nextX = x + eachDir[0];
                        int nextY = y + eachDir[1];
                        if (nextX >= 0 && nextX <= row - 1 && nextY >= 0 && nextY <= col - 1
                            && grid[nextX][nextY] == 1 && !visit[nextX][nextY])
                        {
                            locQueue.push(nextX * col + nextY);
                            visit[nextX][nextY] = true;
                            
                        }
                    }
                }
            }
        }
        return res;
    }
};


int main()
{
    Solution sol;


}