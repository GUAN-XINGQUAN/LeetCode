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

// Brute force approach 1: DFS traverse (not recommended)
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minimum = INT_MAX;
        traverse(triangle, 0, 0, 0, minimum);
        return minimum;
    }
    void traverse(vector<vector<int>>& triangle, int x, int y, int pathSum, int& minimum)
    {
        if (x == triangle.size())
        {
            minimum = min(pathSum, minimum);
            return;
        }
        traverse(triangle, x + 1, y, pathSum + triangle[x][y], minimum);
        traverse(triangle, x + 1, y + 1, pathSum + triangle[x][y], minimum);
    }
};


// Divide and conquer
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return divideConquerHelper(triangle, 0, 0);
    }

    int divideConquerHelper(vector<vector<int>>& triangle, int x, int y)
    {
        if (x == triangle.size())
            return 0;

        int left = divideConquerHelper(triangle, x + 1, y);
        int right = divideConquerHelper(triangle, x + 1, y + 1);
        return min(left, right) + triangle[x][y];
    }
};


// Divide and conquer
// Equation: DP[i][j] = min(DP[i-1][j-1], DP[i-1][j]) + triangle[i][j]
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> DP{ triangle.begin(), triangle.end() };
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                    DP[i][j] = DP[i - 1][j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
                else
                    DP[i][j] = min(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
            }
        }
        
        // find the minimum in the last row of DP
        vector<int> singleRow = DP.back();
        int res = INT_MAX;
        for (int i = 0; i < singleRow.size(); i++)
            res = min(res, singleRow[i]);

        return res;
    }
};


int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    Solution sol;

    int res = sol.minimumTotal(triangle);

    cout << res << endl;
}