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

struct cmp
{
    bool operator() (pair<string, int> p1, pair<string, int> p2)
    {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banSet{ banned.begin(), banned.end() };
        // save in a Hashmap
        vector<string> words = extractWords(paragraph);
        unordered_map<string, int> word2Freq;
        for (auto each : words)
            ++word2Freq[each];

        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for (auto each : word2Freq)
            pq.push(make_pair(each.first, each.second));

        for (int i = 0; i < words.size(); i++)
        {
            auto temp = pq.top();
            pq.pop();
            if (banSet.count(temp.first) == 0)
                return temp.first;
        }
        return "";
    }
    vector<string> extractWords(string paragraph)
    {
        for (int i = 0; i < paragraph.size(); i++)
        {
            if (!isalpha(paragraph[i]))
                paragraph[i] = ' ';
        }
        vector<string> res;
        string word = "";
        for (int i = 0; i < paragraph.size(); i++)
        {
            if (isalpha(paragraph[i]))
                word += tolower(paragraph[i]);
            else
            {
                if (word != "")
                    res.push_back(word);
                word = "";
            }
        }
        if (word != "")
            res.push_back(word);
        return res;
    }
};

int main()
{
    Solution sol;

    string paragraph = "abc abc? abcd the jeff!";

    vector<string> ban = { "abc","abcd","jeff" };

    vector<string> r = sol.extractWords(paragraph);

    /*for (int i = 0; i < r.size(); i++)
        cout << r[i] << endl;*/

    string res = sol.mostCommonWord(paragraph, ban);

    cout << res << endl;
}