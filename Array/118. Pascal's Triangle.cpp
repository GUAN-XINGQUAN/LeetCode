class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
                triangle.push_back({1});
            else if (i == 1)
                triangle.push_back({1, 1});
            else
            {
                vector<int> singleRow (i+1, 0);
                for (int j = 0; j <= i; j++)
                {
                    if (j == 0 || j == i)
                        singleRow[j] = 1;
                    else
                    {
                        singleRow[j] = triangle[i-1][j-1] + triangle[i-1][j];
                    }
                }
                triangle.push_back(singleRow);
            }
        }
        return triangle;
    }
};




/*

0   1   2   3   4   5   6                       

1
1   1   
1   2   1
1   3   3   1
1   4   6   4   1
1   5   10  10  5   1
1   6   15  20  15  6  1


numRows = 4


i = 0
triangle {{1}}

i = 1
triangle {{1}, {1, 1}}

i = 2
singleRow = {0, 0, 0}
    j = 0: singleRow = {1, 0, 0}
    j = 1:

triangle {}

*/