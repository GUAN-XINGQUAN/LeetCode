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
    string numberToWords(int num) {
        string res = convertLessThanThousand(num % 1000);
        vector<string> vec = { "Thousand", "Million", "Billion" };
        for (int i = 0; i < 3; i++)
        {
            num = num / 1000;
            res = num % 1000 != 0 ? convertLessThanThousand(num % 1000) + " " + vec[i] + " " + res : res;
        }
        if (!res.empty())
            while (res.back() == ' ')
                res.pop_back();
        if (res.empty())
            return "Zero";
        else
            return res;
    }
    string convertLessThanThousand(int num)
    {
        vector<string> vec1 = { "", "One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };
        vector<string> vec2 = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
            "Seventy", "Eighty", "Ninety" };
        string res = "";
        int highest = num / 100, twoDigit = num % 100, lastDigit = num % 10;
        if (twoDigit < 20)
            res = vec1[twoDigit];
        else
        {
            if (lastDigit == 0)
                res = vec2[twoDigit / 10];
            else
                res = vec2[twoDigit / 10] + " " + vec1[lastDigit];
        }
        
        if (highest > 0)
        {
            if (twoDigit != 0)
                res = vec1[highest] + " " + "Hundred" + " " + res;
            else
                res = vec1[highest] + " " + "Hundred";
        }
        return res;
    }
};


int main()
{
    Solution sol;
    int num = 100;
    string res = sol.numberToWords(num);
    cout << res << endl;

}