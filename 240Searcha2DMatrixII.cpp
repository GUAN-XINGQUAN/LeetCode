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

// linear scan + binary search ==> time limit exceed
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size() - 1, col = matrix[0].size() - 1;
        for (int i = row; i >= 0; i--)
        {
            if (matrix[i][0] <= target)
            {
                if (binarySearchOneLine2(matrix[i], target))
                    return true;
            }
        }
        return false;
    }

    // binary search I
    bool binarySearchOneLine1(vector<int> oneLine, int target)
    {
        int left = 0, right = oneLine.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (oneLine[mid] == target)
                return true;
            else if (oneLine[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }

    // Alternatively binary search could also be written as follows:
    // Binar search II
    bool binarySearchOneLine2(vector<int> oneLine, int target)
    {
        int left = 0, right = oneLine.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (oneLine[mid] < target)
                left = mid;
            else
                right = mid;
        }
        if (right < left)
            return false;
        else if (oneLine[left] == target || oneLine[right] == target)
            return true;
        else
            return false;
    }
};

// move from bottom left to upper right
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        int rowIndex = matrix.size() - 1, colIndex = 0;
        while (true)
        {
            if (rowIndex < 0 || colIndex > matrix[0].size() - 1)
                return false;
            if (matrix[rowIndex][colIndex] == target)
                return true;
            else if (matrix[rowIndex][colIndex] < target)
                colIndex++;
            else
                rowIndex--;
        }
    }
};

int main()
{
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15} ,
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    vector<vector<int>> matrix = { {1}, {5} };
    int target = 5;
    Solution sol;
    if (sol.searchMatrix(matrix, target))
        cout << "Yes\n";
    else
        cout << "No\n";
}