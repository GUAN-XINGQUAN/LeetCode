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

// brute force
class Solution {
public:
    bool isUgly(int num) {
        if (num == 0)
            return false;
        while (num % 2 == 0)
            num = num / 2;
        while (num % 3 == 0)
            num = num / 3;
        while (num % 5 == 0)
            num = num / 5;

        if (num == 1)
            return true;
        return false;
    }
};

int main()
{
    int num = 14;

    Solution sol;

    if (sol.isUgly(num))
        cout << "YES\n";
    else
        cout << "NO\n";
}