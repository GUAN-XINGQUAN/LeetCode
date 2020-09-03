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

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while (j < typed.size())
        {
            // two chars are the same
            if (name[i] == typed[j])
            {
                i++;
                j++;
            }
            else
            {
                // 1st char is different
                if (j == 0)
                    return false;
                // other chars
                else
                {
                    if (typed[j] == typed[j - 1])
                        j++;
                    else
                        return false;
                }
            }
        }
        if (i == name.size())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;

}