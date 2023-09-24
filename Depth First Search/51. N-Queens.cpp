class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtracking(board, result, 0);
        return result;
    }
    void backtracking(vector<string>& board, vector<vector<string>>& allSolutions, int row)
    {
        // base case
        if (row == board.size())
        {
            allSolutions.push_back(board);
            return;
        }
        for (int i = 0; i < board[row].size(); i++)
        {
            if (isValid(board, row, i))
            {
                board[row][i] = 'Q';
                backtracking(board, allSolutions, row+1);
                board[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& board, int row, int col)
    {
        // if I put Q at board[row][col], is this row-wise okay?
        for (int i = 0; i < col; i++)
        {
            if (board[row][i] == 'Q')
                return false;
        }
        // If I put Q at board[row][col], is this column-wise okay?
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        // If I put Q at board[row][col], is this diagnoal line okay?
        for (int i = row-1, j = col-1; i >=0 && j>= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // If I put Q at board[row][col], is this off-diagnoal line okay?
        for (int i = row-1, j = col+1; i >=0 && j < board[row].size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};