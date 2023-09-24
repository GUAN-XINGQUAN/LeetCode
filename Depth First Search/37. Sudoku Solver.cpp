/*
1. At each cell, try a number between 1 to 9
2. If current filling is valid, then move to the next cell.
3. Otherwise, try a different number.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
    bool solver(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // we don't care cells with numbers already
                if (board[i][j] != '.')
                    continue;
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isValid(board, i, j, ch))
                    {
                        board[i][j] = ch;
                        if (solver(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                // If no numbers between 1 to 9 cause a valid sudoku, then return false
                return false;
            }
        }
        // If all numbers are already filled on the board, then we don't need to fill anything.
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char ch)
    {
        // if I fill ch at board[row][col], is this row-wise okay?
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == ch)
                return false;
        }
        // If I fill ch at board[row][col], is this column-wise okay?
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == ch)
                return false;
        }
        // If I fill ch at board[row][col], is this square-wise okay?
        for (int i = (row/3)*3; i < (row/3+1)*3; i++)
        {
            for (int j = (col/3)*3; j < (col/3+1)*3; j++)
            {
                if (board[i][j] == ch)
                    return false;
            }
        }
        return true;
    }
};