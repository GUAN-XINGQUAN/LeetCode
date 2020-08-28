#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
#include "listNodeVisualization.h"

using namespace std;

// Recursion
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        for (int i = 2; i < A.size(); i++)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = dp[i - 1] + 1;
        }

        int res = 0;
        for (int i = 0; i < dp.size(); i++)
            res += dp[i];
        return res;
    }
};



int main()
{

}