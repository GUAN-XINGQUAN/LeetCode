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
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++)
        {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int eachL : left)
                {
                    for (int eachR : right)
                    {
                        switch (ch)
                        {
                        case '+':
                            res.push_back(eachL + eachR);
                            break;
                        case '-':
                            res.push_back(eachL - eachR);
                            break;
                        case '*':
                            res.push_back(eachL * eachR);
                        }
                    }
                }
            }
        }
        if (onlyOneNumber(input))
            res.push_back(stoi(input));

        return res;
    }
    bool onlyOneNumber(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (!isdigit(str[i]))
                return false;
        }
        return true;
    }
};


int main()
{
    Solution sol;

    string inputs = "2+1";

    vector<int> res = sol.diffWaysToCompute(inputs);

}