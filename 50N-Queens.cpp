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

// Recursion
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queens(n, string(n, '.'));
        solveHelper(queens, res, 0);
        return res;
    }
    void solveHelper(vector<string>& queens, vector<vector<string>>& res, int curRow)
    {
        int n = queens.size();
        if (curRow == n)
        {
            res.push_back(queens);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isValidPlacement(queens, curRow, i))
            {
                queens[curRow][i] = 'Q';
                solveHelper(queens, res, curRow + 1);
                queens[curRow][i] = '.';
            }
        }
    }
    bool isValidPlacement(vector<string>& queens, int row, int col)
    {
        // This function is used to check whether the queen is placed in an appropriate spot
        // Check if same row has two queens or not
        for (int i = 0; i < row; i++)
        {
            if (queens[i][col] == 'Q')
                return false;
        }
        // Check diagonal line
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (queens[i][j] == 'Q')
                return false;
        }
        // Check diagonal line
        for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); i--, j++)
        {
            if (queens[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<string>> res = sol.solveNQueens(n);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
}