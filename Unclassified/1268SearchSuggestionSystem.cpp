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
#include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        
        string str = "";
        for (int i = 0; i < searchWord.size(); i++)
        {
            str += searchWord[i];
            auto it = lower_bound(products.begin(), products.end(), str);
            vector<string> temp;
            for (int j = 0; j < 3 && it != products.end(); j++, it++)
            {
                if (str == (*it).substr(0, str.size()))
                    temp.push_back(*it);
            }
            res.push_back(temp);
        }
        return res;
    }

};


int main()
{
    Solution sol;
    vector<string> products = { "mobile","mouse","moneypot","monitor","mousepad" };
    string searchWord = "mouse";

    vector<vector<string>> res = sol.suggestedProducts(products, searchWord);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << '\t';
        cout << endl;
    }
}