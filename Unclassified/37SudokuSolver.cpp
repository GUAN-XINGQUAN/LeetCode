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

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        DFSHelper(board, 0, 0);
    }

    bool DFSHelper(vector<vector<char>>& board, int posX, int posY)
    {
        // base case
        if (posX >= 9)
            return true;
        if (posY >= 9)
            return DFSHelper(board, posX + 1, 0);
        if (board[posX][posY] != '.')
            return DFSHelper(board, posX, posY + 1);
        for (char ch = '1'; ch <= '9'; ch++)
        {
            if (!isValid(board, posX, posY, ch))
                continue;
            board[posX][posY] = ch;
            if (DFSHelper(board, posX, posY + 1))
                return true;
            board[posX][posY] = '.';
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int posX, int posY, char value)
    {
        // check the column line
        for (int i = 0; i < 9; i++)
        {
            if (board[i][posY] == value)
                return false;
        }
        // check the same row
        for (int j = 0; j < 9; j++)
        {
            if (board[posX][j] == value)
                return false;
        }
        // check the 3X3 cells
        int xx = posX - posX % 3, yy = posY - posY % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + xx][j + yy] == value)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;


}