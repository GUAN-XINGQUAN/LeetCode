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

// recursion with memory
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> word2Comb;
        return helper(s, wordDict, word2Comb);
    }
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& word2Comb)
    {
        if (word2Comb.count(s))
            return word2Comb[s];
        if (s.empty())
            return { "" };
        vector<string> res;
        for (string word : wordDict)
        {
            if (s.substr(0, word.size()) != word)
                continue;
            vector<string> memo = helper(s.substr(word.size()), wordDict, word2Comb);
            for (string str : memo)
            {
                string temp = " ";
                if (str.empty())
                    temp = "";
                res.push_back(word + temp + str);
            }
        }
        word2Comb[s] = res;
        return res;
    }
};


int main()
{
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
    vector<string> res = sol.wordBreak(s, wordDict);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
}