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

struct cmp
{
    // using passing by reference to save the time and space
    bool operator()(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int, vector<int>, less<int>> pq;
        sort(courses.begin(), courses.end(), cmp());

        int startDay = 0;
        for (int i = 0; i < courses.size(); i++)
        {
            startDay += courses[i][0];
            pq.push(courses[i][0]);
            if (startDay > courses[i][1])
            {
                startDay -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};


int main()
{
    Solution sol;

}