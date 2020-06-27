#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorIntVisualization.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // edge case
        if (matrix.size()==0)
            return false;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (isInLine(matrix[i], target))
            {
                int left = 0, right = matrix[i].size() - 1;
                while (left + 1 < right)
                {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] < target)
                        left = mid;
                    else
                        right = mid;
                }
                if (matrix[i][left] == target)
                    return true;
                if (matrix[i][right] == target)
                    return true;
            }
        }
        return false;
    }

    bool isInLine(vector<int> oneLine, int target)
    {
        if (oneLine.empty())
            return false;
        if (oneLine.size() == 1 && oneLine[0] != target)
            return false;
        if (oneLine.front() <= target && oneLine.back() >= target)
            return true;
        else
            return false;
    }
};

int main()
{
    // ordinary case
    vector<vector<int>> matrix1 = {

        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };

    // edge case
    vector<vector<int>> matrix = { {} };
    int  target = 1;
 
    Solution sol;
    if (sol.searchMatrix(matrix, target))
        cout << "YES\n";
    else
        cout << "No\n";

}