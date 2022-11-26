/*


*/

// Binary search
// time O(log mn)
// space O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};