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
    string convertToBase7(int num) {
        int high = 0, sum = 1, absNum = abs(num);
        // determine the highest digit 7 ** high
        while (sum <= absNum)
        {
            sum = sum * 7;
            high++;
        }

        // convert the number to base of 7
        string res = "";
        while (high >= 0)
        {
            int digit = absNum / sum;
            absNum = absNum % sum;
            sum /= 7;
            res += to_string(digit);
            high--;
        }
        
        if (res.size() > 1 && res[0] == '0')
            res = res.substr(1);

        return num >= 0 ? res : "-"+res;
    }
};
int main()
{
    Solution sol;
    int n = -8;
    string res = sol.convertToBase7(n);
    cout << res << endl;
}