class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        // Calculate the cumulative matrix
        vector<vector<int>> cumuMat (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++)
        {
            int rowSum = 0;
            for (int j = 0; j < n; j++)
            {
                rowSum += mat[i][j];
                if (i > 0)
                    cumuMat[i][j] += cumuMat[i-1][j] + rowSum;
                else
                    cumuMat[i][j] = rowSum;
            }
        }
        
        // Use cumulative matrix to compute answer matrix
        vector<vector<int>> answer (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int upperI = i + k, upperJ = j + k, lowerI = i - k, lowerJ = j - k;
                upperI = min(m-1, upperI);
                upperJ = min(n-1, upperJ);
                if (lowerI <= 0 && lowerJ <= 0)
                    answer[i][j] = cumuMat[upperI][upperJ];
                else if (lowerI <= 0 && lowerJ > 0)
                    answer[i][j] = cumuMat[upperI][upperJ] - cumuMat[upperI][lowerJ-1];
                else if (lowerI > 0 && lowerJ <= 0)
                    answer[i][j] = cumuMat[upperI][upperJ] - cumuMat[lowerI-1][upperJ];
                else
                    answer[i][j] = cumuMat[upperI][upperJ] - cumuMat[upperI][lowerJ-1] - cumuMat[lowerI-1][upperJ] + cumuMat[lowerI-1][lowerJ-1];
            }
        }
        
        return answer;
    }
};