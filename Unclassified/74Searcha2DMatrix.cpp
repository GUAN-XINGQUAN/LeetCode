#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorCharVisualization.h"

using namespace std;

// Linear scan + Binary search
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size(), col = matrix[0].size();

        // Linear scan
        for (int i = 0; i < row; i++)
        {
            if (isInLine(matrix[i], target))
            {
                // Binary search
                int left = 0, right = col - 1;
                while (left + 1 < right)
                {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] < target)
                        left = mid;
                    else
                        right = mid;
                }
                // Consider all possible cases
                if (col == 1 && matrix[i][left] != target)
                    return false;
                else if (matrix[i][left] == target)
                    return true;
                else if (matrix[i][right] == target)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    bool isInLine(vector<int> line, int target)
    {
        if (line.empty())
            return false;
        else if (line.front() > target || line.back() < target)
            return false;
        else
            return true;
    }
};

// Binary search + binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // all edge cases
        if (matrix.empty() || matrix[0].empty())
            return false;
        if (matrix[0][0] > target || matrix.back().back() < target)
            return false;
        int line = findWhichLine(matrix, target);

        // Binary search to find whether it has in this line or not.
        if (line == -1)
            return false;
        // cout << line << endl;
        int left = 0, right = matrix[line].size()-1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[line][mid] < target)
                left = mid;
            else
                right = mid;
        }
        if (matrix[line][left] == target)
            return true;
        else if (matrix[line][right] == target)
            return true;
        else
            return false;
    }

    int findWhichLine(vector<vector<int>>& matrix, int target)
    {
        int row = matrix.size(), col = matrix[0].size();
        //Binary search to find which line
        int top = 0, bottom = row - 1;
        while (top + 1 < bottom)
        {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][0] < target)
                top = mid;
            else
                bottom = mid;
        }
        if (matrix[top][0] <= target && matrix[top].back()>= target)
            return top;
        else if (matrix[bottom][0] <= target && matrix[bottom].back() >= target)
            return bottom;
        else
            return -1;
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
    vector<vector<int>> matrix2 = { {} };
    
    // edge case
    vector<vector<int>> matrix = { {1}, {13}, {15} };
    
    
    int  target = 15;

    Solution sol;
    if (sol.searchMatrix(matrix, target))
        cout << "YES\n";
    else
        cout << "No\n";

}