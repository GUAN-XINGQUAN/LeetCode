#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0)
            return true;

        int left = 0, right = sqrt(c);

        while (left <= right)
        {
            // avoid numeric overflow
            int residual = c - right * right;
            if (residual == left  * left)
                return true;
            else if (residual < left * left)
                right--;
            else
                left++;
        }
        return false;
    }
};


int main()
{
    Solution sol;

}