#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, bot = n - 1, left = 0, right = n - 1, val = 1;
        while (true)
        {
            // from left to right
            for (int j = left; j <= right; j++)
            {
                res[up][j] = val;
                val++;
            }
            up++;
            if (up > bot)
                break;
            // from top to bottom
            for (int i = up; i <= bot; i++)
            {
                res[i][right] = val;
                val++;
            }
            right--;
            if (right < left)
                break;
            // from right to left
            for (int j = right; j >= left; j--)
            {
                res[bot][j] = val;
                val++;
            }
            bot--;
            if (bot < up)
                break;
            // from bottom to top
            for (int i = bot; i >= up; i--)
            {
                res[i][left] = val;
                val++;
            }
            left++;
            if (left > right)
                break;
        }
        return res;
    }
};


int main()
{
    Solution sol;

    vector<vector<int>> res = sol.generateMatrix(3);

    nestedVectorIntVisualization(res);
}