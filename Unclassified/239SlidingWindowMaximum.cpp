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

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!pq.empty() && pq.top().second <= i - k)
                pq.pop();
            pq.push(make_pair(nums[i], i));
            if (i >= k - 1)
                res.push_back(pq.top().first);
        }
        return res;
    }
};


int main()
{
    vector<int> nums = { 9, 10, 9, -7, -4, -8, 2, -6 };
    Solution sol;

    vector<int> res = sol.maxSlidingWindow(nums, 5);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}