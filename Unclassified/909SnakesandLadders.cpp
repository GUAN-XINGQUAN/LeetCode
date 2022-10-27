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
    int snakesAndLadders(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<bool> visit(row*col+1, false);
        queue<int> locQueue({ 1 });
        int res = 0;
        while (!locQueue.empty())
        {
            for (int i = locQueue.size(); i > 0; i--)
            {
                int tempLoc = locQueue.front();
                locQueue.pop();
                if (tempLoc == row * col)
                    return res;
                for (int j = 1; j <= 6 && tempLoc + j <= row * col; j++)
                {
                    vector<int> pos = getPosition(tempLoc + j, col);
                    int nextLoc;
                    if (board[pos[0]][pos[1]] == -1)
                        nextLoc = tempLoc + j;
                    else
                        nextLoc = board[pos[0]][pos[1]];
                    if (visit[nextLoc] == true)
                        continue;
                    locQueue.push(nextLoc);
                    visit[nextLoc] = true;
                }
            }
            res++;
        }
        return -1;
    }
    vector<int> getPosition(int location, int col)
    {
        int rowIndex = (location-1) / col, colIndex = (location-1) % col;
        if (rowIndex % 2 != 0)
            colIndex = col - 1 - colIndex;
        rowIndex = col - 1 - rowIndex;

        return vector<int> {rowIndex, colIndex};
    }
};


int main()
{
    Solution sol;

    vector<vector<int>> board = {
        {-1, -1, -1},
        {-1,-1,-1},
        {-1,-1,-1} };

    int res = sol.snakesAndLadders(board);
    cout << res << endl;
}