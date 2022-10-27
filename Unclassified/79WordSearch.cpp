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

// DFS
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // no edge case because board is guaranteed to be not empty

        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        const vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, };
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (DFSHelper(board, word, 0, i, j, row, col, visit, dirs))
                    return true;
            }
        }
        return false;
    }

    bool DFSHelper(vector<vector<char>>& board, string word, int count, int i, int j, int row, int col,
        vector<vector<bool>>& visit, const vector<vector<int>>& dirs)
    {
        // base case
        if (count == word.size())
            return true;
        if (i < 0 || i >= row || j < 0 || j >= col || visit[i][j] || board[i][j] != word[count])
            return false;

        // recursion
        visit[i][j] = true;
        bool res = false;
        for (vector<int> eachDir : dirs)
        {
            res = res || DFSHelper(board, word, count + 1, i + eachDir[0], j + eachDir[1], row, col, visit, dirs);
        }
        visit[i][j] = false;
        return res;
    }
};

int main()
{
    Solution sol;


}