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

// Use heap
struct cmp
{
    bool operator() (pair<string, int> p1, pair<string, int> p2)
    {
        if (p1.second < p2.second)
            return true;
        else if (p1.second == p2.second)
        {
            if (p1.first > p2.first)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> str2Freq;
        for (auto each : words)
            ++str2Freq[each];
        priority_queue <pair<string, int>, vector<pair<string, int>>, cmp> pQ;

        for (auto each : str2Freq)
            pQ.push(make_pair(each.first, each.second));

        for (int i = 0; i < k; i++)
        {
            auto temp = pQ.top();
            pQ.pop();
            res.push_back(temp.first);
        }
        return res;
    }
};


int main()
{
    vector<string> vec = { "i", "love", "guan", "z", "love", "guan" };
    int k = 2;
    Solution sol;

    vector<string> res = sol.topKFrequent(vec, k);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}