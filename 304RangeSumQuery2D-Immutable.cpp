class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // Initialize the member matrix
        m_mat = matrix;
        // Compute the cumulative matrix
        m_cumuMat.resize(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++)
        {
            int rowSum = 0;
            for (int j = 0; j < n; j++)
            {
                rowSum += m_mat[i][j];
                if (i > 0)
                    m_cumuMat[i][j] += m_cumuMat[i-1][j] + rowSum;
                else
                    m_cumuMat[i][j] += rowSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Call the cumulative matrix to solve
        int res = 0;
        if (row1 == 0 && col1 == 0)
            res = m_cumuMat[row2][col2];
        else if (row1 == 0 && col1 != 0)
            res = m_cumuMat[row2][col2] - m_cumuMat[row2][col1-1];
        else if (row1 != 0 && col1 == 0)
            res = m_cumuMat[row2][col2] - m_cumuMat[row1-1][col2];
        else
            res = m_cumuMat[row2][col2] - m_cumuMat[row1-1][col2] - m_cumuMat[row2][col1-1] + m_cumuMat[row1-1][col1-1];
        
        return res;
    }
private:
    vector<vector<int>> m_mat;
    vector<vector<int>> m_cumuMat;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */