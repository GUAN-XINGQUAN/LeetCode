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
#include "listNodeVisualization.h"

using namespace std;

struct cmp
{
    bool operator()(string str1, string str2)
    {
        int i = 0, j = 0;
        string identifer1 = "", identifer2 = "";
        while (i < str1.size() && str1[i] != ' ')
        {
            identifer1 += str1[i];
            i++;
        }
        while (j < str2.size() && str2[j] != ' ')
        {
            identifer2 += str2[j];
            j++;
        }
        string res1 = str1.substr(i, str1.size() - i+1);
        string res2 = str2.substr(j, str2.size() - j + 1);
        if (res1 < res2)
            return true;
        else
        {
            if (res1 == res2)
                return identifer1 < identifer2;
            else
                return false;
        }
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLog, letterLog, res;
        for (int i = 0; i < logs.size(); i++)
        {
            if (isDigitLog(logs[i]))
                digitLog.push_back(logs[i]);
            else
                letterLog.push_back(logs[i]);
        }
        sort(letterLog.begin(), letterLog.end(), cmp());
        for (auto each : letterLog)
            res.push_back(each);
        for (auto each : digitLog)
            res.push_back(each);
        return res;
    }
    bool isDigitLog(string log)
    {
        int left = 0;
        while (left < log.size() && log[left] != ' ')
            left++;
        if (isdigit(log[left+1]))
            return true;
        else
            return false;
    }
};


int main()
{
    Solution sol;

    vector<string> logs = { "dig1 8 1 5 1",
        "let1 art can",
        "dig2 3 6",
        "let2 own kit dig",
        "let3 art zero" };

    
    vector<string> res = sol.reorderLogFiles(logs);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
}