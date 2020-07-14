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

using namespace std;

// Solution 1: non-recursive solution
class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        vector<string> strVec = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        unordered_map<int, string> num2Str;
        for (int i = 2; i <= 9; i++)
            num2Str[i] = strVec[i - 2];
        vector<string> res = { "" };
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> tempVec;
            string tempStr = num2Str[digits[i] - '0'];
            for (int j = 0; j < tempStr.size(); j++)
            {
                for (auto each : res)
                    tempVec.push_back(each + tempStr[j]);
            }
            res = tempVec;
        }
        return res;
    }
};


// Solution 2: DFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        vector<string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> res;
        DFS(digits, 0, letters, res, "");
        return res;
    }
    void DFS(string digits, int count, vector<string> letters, vector<string>& res, string out)
    {
        if (count == digits.size())
        {
            res.push_back(out);
            return;
        }
        string str = letters[digits[count] - '0'];
        for (int i = 0; i < str.size(); i++)
            DFS(digits, count + 1, letters, res, out + str[i]);
    }
};


int main()
{
    string digits = "23";
    Solution sol;

    vector<string> res = sol.letterCombinations(digits);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}