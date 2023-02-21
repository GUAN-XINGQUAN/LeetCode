class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // no edge case per problem statement
        int m = mat.size(), n = mat[0].size();
        // invalid input arguments
        if (m * n != r * c)
            return mat;
        // fill the new matrix one element by one element
        vector<vector<int>> reshaped (r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int index = i * c + j;
                int originalRow = index / n, originalCol = index % n;
                reshaped[i][j] = mat[originalRow][originalCol];
            }
        }
        return reshaped;
    }
};


/*
    a   b   c
    d   e   f
    m * n
    2 * 3


    a   b
    c   d
    e   f

    r * c
    3 * 2

    i = 1, j = 0
    index = 1 * 2 + 0 = 2

    originalRow = 2 / 3 = 0
    originalCol = 2 % 3 = 2

*/