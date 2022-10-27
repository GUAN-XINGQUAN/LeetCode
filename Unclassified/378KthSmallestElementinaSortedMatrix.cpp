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


// Use heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int>> pQ;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                pQ.push(matrix[i][j]);
                if (pQ.size() > k)
                    pQ.pop();
            }
        }
        return pQ.top();
    }
};


int main()
{
    vector<vector<int>> mat = {
        {1,5,9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    Solution sol;
    int res = sol.kthSmallest(mat, k);
    cout << res << endl;
}
