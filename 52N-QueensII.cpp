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
    int totalNQueens(int n) {
        int res = 0;
        vector<string> queens(n, string(n, '.'));
        solveHelper(queens, 0, res);
        return res;
    }
    void solveHelper(vector<string>& queens, int curRow, int& res)
    {
        int n = queens.size();
        if (curRow == n)
            res++;
        for (int i = 0; i < n; i++)
        {
            if (isValidPlacement(queens, curRow, i))
            {
                queens[curRow][i] = 'Q';
                solveHelper(queens, curRow+1, res);
                queens[curRow][i] = '.';
            }
        }
    }
    bool isValidPlacement(vector<string> queens, int row, int col)
    {
        // vertical line
        for (int i = 0; i < queens.size(); i++)
        {
            if (queens[i][col] == 'Q')
                return false;
        }
        // diagonal line
        for (int i = row-1, j=col-1; i >=0 && j >= 0; i--, j--)
        {
            if (queens[i][j] == 'Q')
                return false;
        }
        // off-diagonal line
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
    
    int res = sol.totalNQueens(4);

    cout << res << endl;
}