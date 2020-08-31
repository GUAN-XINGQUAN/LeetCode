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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // edge case
        if (matrix.empty() || matrix[0].empty())
            return {};

        int row = matrix.size(), col = matrix[0].size();
        queue<int> locQueuePacific, locQueueAtlantic;
        vector<vector<bool>> visitPacific(row, vector<bool>(col, false));
        vector<vector<bool>> visitAtlantic(row, vector<bool>(col, false));
        vector<vector<int>> res;

        for (int i = 0; i < row; i++)
        {
            locQueuePacific.push(i * col + 0);
            locQueueAtlantic.push(i * col + col - 1);
            visitPacific[i][0] = true;
            visitAtlantic[i][col - 1] = true;
        }

        for (int j = 0; j < col; j++)
        {
            locQueuePacific.push(0 * col + j);
            locQueueAtlantic.push((row - 1) * col + j);
            visitPacific[0][j] = true;
            visitAtlantic[row - 1][j] = true;
        }

        BFSHelper(matrix, visitPacific, locQueuePacific);
        BFSHelper(matrix, visitAtlantic, locQueueAtlantic);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (visitPacific[i][j] && visitAtlantic[i][j])
                    res.push_back({ i, j });
            }
        }
        return res;
    }
    void BFSHelper(vector<vector<int>>& matrix, vector<vector<bool>>& visit, queue<int> locQueue)
    {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        while (!locQueue.empty())
        {
            int temp = locQueue.front();
            locQueue.pop();
            int x = temp / col, y = temp % col;
            for (auto eachDir : dirs)
            {
                int nextX = x + eachDir[0];
                int nextY = y + eachDir[1];
                if (nextX >= 0 && nextX <= row - 1 && nextY >= 0 && nextY <= col - 1
                    && matrix[nextX][nextY] >= matrix[x][y] && !visit[nextX][nextY])
                {
                    visit[nextX][nextY] = true;
                    locQueue.push(nextX * col + nextY);
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4} };

    vector<vector<int>> res = sol.pacificAtlantic(matrix);
}