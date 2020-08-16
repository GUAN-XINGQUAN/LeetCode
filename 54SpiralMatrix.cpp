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

// Four directions
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // edge case
        if (matrix.empty() || matrix[0].empty())
            return {};

        int row = matrix.size(), col = matrix[0].size();
        int index = 0, i = 0, j = 0;
        vector<int> res;
        vector<pair<int, int>> dirs{ {0, 1},{1, 0,},{0, -1},{-1, 0} };
        vector<vector<bool>> visit(row, vector<bool>(col, false));

        for (int k = 0; k < row * col; k++)
        {
            res.push_back(matrix[i][j]);
            visit[i][j] = true;
            int x = i + dirs[index].first, y = j + dirs[index].second;
            if (x < 0 || x >= row || y < 0 || y >= col || visit[x][y] == true)
            {
                index = (index + 1) % 4;
                x = i + dirs[index].first;
                y = j + dirs[index].second;
            }
            i = x;
            j = y;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> res = sol.spiralOrder(matrix);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}