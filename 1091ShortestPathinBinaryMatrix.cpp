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

// list all 8 directions
class Solution1 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // edge case
        if (grid.empty() || grid[0].empty() || grid[0][0] == 1 || grid.back().back() == 1)
            return -1;

        int row = grid.size(), col = grid.size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        queue<int> locQueue ({0});
        visit[0][0] = true;
        // BFS
        int res = 0;
        while (!locQueue.empty())
        {
            res++;
            for (int i = locQueue.size(); i > 0; i--)
            {
                int temp = locQueue.front();
                locQueue.pop();
                int x = temp / col, y = temp % col;
                if (x == row - 1 && y == col - 1)
                    return res;
                // up direction
                if (x > 0 && grid[x - 1][y] != 1 && !visit[x - 1][y])
                {
                    locQueue.push(temp - col);
                    visit[x - 1][y] = true;
                }
                // down direction
                if (x < row - 1 && grid[x + 1][y] != 1 && !visit[x + 1][y])
                {
                    locQueue.push(temp + col);
                    visit[x + 1][y] = true;
                }
                // left direction
                if (y > 0 && grid[x][y - 1] != 1 && !visit[x][y - 1])
                {
                    locQueue.push(temp - 1);
                    visit[x][y - 1] = true;
                }
                // right direction
                if (y < col - 1 && grid[x][y + 1] != 1 && !visit[x][y + 1])
                {
                    locQueue.push(temp + 1);
                    visit[x][y + 1] = true;
                }
                // up-left direction
                if (x > 0 && y > 0 && grid[x - 1][y - 1] != 1 && !visit[x - 1][y - 1])
                {
                    locQueue.push(temp - col - 1);
                    visit[x - 1][y - 1] = true;
                }
                // up-right direction
                if (x > 0 && y < col - 1 && grid[x - 1][y + 1] != 1 && !visit[x - 1][y + 1])
                {
                    locQueue.push(temp - col + 1);
                    visit[x - 1][y + 1] = true;
                }
                // down-left direction
                if (x < row - 1 && y > 0 && grid[x + 1][y - 1] != 1 && !visit[x + 1][y - 1])
                {
                    locQueue.push(temp + col - 1);
                    visit[x + 1][y - 1] = true;
                }
                // down-right direction
                if (x < row - 1 && y < col - 1 && grid[x + 1][y + 1] != 1 && !visit[x + 1][y + 1])
                {
                    locQueue.push(temp + col + 1);
                    visit[x + 1][y + 1] = true;
                }
            }
        }
        return -1;
    }
};


// use loop to represent 8 directions
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // edge case
        if (grid.empty() || grid[0].empty() || grid[0][0] == 1 || grid.back().back() == 1)
            return -1;

        // directions: up, down, left, right, up-left, up-right, down-left, down-right
        vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
        int row = grid.size(), col = grid.size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        queue<int> locQueue({ 0 });
        visit[0][0] = true;
        // BFS
        int res = 0;
        while (!locQueue.empty())
        {
            res++;
            for (int i = locQueue.size(); i > 0; i--)
            {
                int temp = locQueue.front();
                locQueue.pop();
                int x = temp / col, y = temp % col;
                if (x == row - 1 && y == col - 1)
                    return res;
                // up direction
                for (auto eachDir : dirs)
                {
                    int nextX = x + eachDir[0];
                    int nextY = y + eachDir[1];
                    if (nextX >= 0 && nextX <= row - 1 && nextY >= 0 && nextY <= col - 1 && grid[nextX][nextY] != 1
                        && !visit[nextX][nextY])
                    {
                        locQueue.push(nextX * col + nextY);
                        visit[nextX][nextY] = true;
                    }
                }
            }
        }
        return -1;
    }
};


int main()
{
    Solution sol;
}