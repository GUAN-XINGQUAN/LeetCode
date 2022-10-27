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
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int i = 0, j = 0, val1 = 0, val2 = 0;
        string str1 = "", str2 = "";
        while (i < m || j < n)
        {
            if (i >= m)
                str1 += "0";
            if (j >= n)
                str2 += "0";
            while (i < m && version1[i] != '.')
                str1 += version1[i++];
            while (j < n && version2[j] != '.')
                str2 += version2[j++];
            val1 = stoi(str1);
            val2 = stoi(str2);
            if (val1 > val2)
                return 1;
            else if (val1 < val2)
                return -1;
            else
            {
                str1 = "";
                str2 = "";
                i++;
                j++;
            }
        }
        return 0;
    }
};


int main()
{
    Solution sol;
    string version1 = "1.01", version2 = "1.001";
    int res = sol.compareVersion(version1, version2);

    cout << res << endl;
}