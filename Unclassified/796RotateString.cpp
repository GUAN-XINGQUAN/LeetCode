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
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        int m = A.size(), n = B.size();
        // edge case
        if (m != n)
            return false;
        if (m == 0 || m == 1)
            return true;

        for (int i = 0; i < m; i++)
        {
            rotateHelper(A);
            if (A == B)
                return true;
        }
        return false;
    }
    void rotateHelper(string& str)
    {
        int m = str.size();
        str = str.substr(1, m - 1) + str[0];
    }
};


int main()
{
    Solution sol;
}