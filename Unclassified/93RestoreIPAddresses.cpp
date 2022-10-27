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

// BFS
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string out = "";
        int total = 4;
        DFSHelper(s, total, out, res);
        return res;
    }
    void DFSHelper(string s, int total, string out, vector<string>& res)
    {
        if (total == 0)
        {
            if (s.empty())
                res.push_back(out);
        }
        else
        {
            for (int i = 1; i <= 3; i++)
            {
                if (s.size() >= i && isValid(s.substr(0, i)))
                {
                    if (total == 1)
                        DFSHelper(s.substr(i), total - 1, out + s.substr(0, i), res);
                    else
                        DFSHelper(s.substr(i), total - 1, out + s.substr(0, i) + ".", res);
                }
            }
        }
    }
    bool isValid(string str)
    {
        // longer than 3 digits
        if (str.size() > 3)
            return false;
        // equal to 3 digits
        else if (str.size() == 3)
        {
            if (str[0] == '0')
                return false;
            if (stoi(str) > 255)
                return false;
        }
        else if (str.size() == 2)
        {
            if (str[0] == '0')
                return false;
        }
        else
            return true;
        
    }
};

int main()
{
    Solution sol;

    string s = "25525511135";

    vector<string> res = sol.restoreIpAddresses(s);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    //if (sol.isValid("563"))
    //    cout << "YES\n";
    //else
    //    cout << "No\n";

}