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
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i != 0 && i != row - 1 && j != 0 && j != col - 1)
                    continue;
                if (board[i][j] != 'O')
                    continue;
                board[i][j] = '$';
                int root = i * col + j;
                queue<int> borderQueue({ root });
                // BFS
                while (!borderQueue.empty())
                {
                    int loc = borderQueue.front();
                    borderQueue.pop();
                    int rowCoord = loc / col, colCoord = loc % col;
                    if (rowCoord >= 1 && board[rowCoord - 1][colCoord] == 'O')
                    {
                        board[rowCoord - 1][colCoord] = '$';
                        borderQueue.push(loc-col);
                    }
                    if (rowCoord <= row - 2 && board[rowCoord+1][colCoord] == 'O')
                    {
                        board[rowCoord + 1][colCoord] = '$';
                        borderQueue.push(loc+col);
                    }
                    if (colCoord >= 1 && board[rowCoord][colCoord-1] == 'O')
                    {
                        board[rowCoord][colCoord - 1] = '$';
                        borderQueue.push(loc-1);
                    }
                    if (colCoord <= col-2 && board[rowCoord][colCoord+1] == 'O')
                    {
                        board[rowCoord][colCoord + 1] = '$';
                        borderQueue.push(loc+1);
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
    }
};

int main()
{
    vector<vector<char>> board = { {'X','X', 'X', 'X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'} };

    Solution sol;
    sol.solve(board);
    nestedVectorCharVisualization(board);
}