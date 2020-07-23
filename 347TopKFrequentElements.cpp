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


// Raw writing
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        unordered_map<int, int> num2Count;
        for (int i = 0; i < nums.size(); i++)
            ++num2Count[nums[i]];

        priority_queue<int, vector<int>, less<int>> pQ;
        auto it1 = num2Count.begin();
        while (it1 != num2Count.end())
        {
            pQ.push(it1->second);
            it1++;
        }

        for (int i = 0; i < k; i++)
        {
            int temp = pQ.top();
            pQ.pop();
            it1 = num2Count.begin();
            while (it1 != num2Count.end())
            {
                if (it1->second == temp)
                    break;
                it1++;
            }
            res.push_back(it1->first);
            num2Count.erase(it1->first);
        }
        return res;
    }
};


// Optimized writing
struct cmp{
    bool operator() (pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first > p2.first)
            return false;
        else
            return true;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> num2Freq;
        for (int i = 0; i < nums.size(); i++)
            ++num2Freq[nums[i]];
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pQ;
        for (auto each : num2Freq)
            pQ.push(make_pair(each.second, each.first));
        for (int i = 0; i < k; i++)
        {
            auto temp = pQ.top();
            pQ.pop();
            res.push_back(temp.second);
        }
        return res;
    }
};


int main()
{
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    Solution sol;

    vector<int> res = sol.topKFrequent(nums, k);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}
