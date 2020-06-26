#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "NestedVectorIntVisualization.h"

using namespace std;

// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>{});
        vector<int> inDegree(numCourses);
        for (vector<int> eachPair : prerequisites)
        {
            graph[eachPair[1]].push_back(eachPair[0]);
            ++inDegree[eachPair[0]];
        }
        queue<int> courseQueue;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
                courseQueue.push(i);
        }
        while (!courseQueue.empty())
        {
            int tempCouse = courseQueue.front();
            courseQueue.pop();
            for (auto eachCourse : graph[tempCouse])
            {
                --inDegree[eachCourse];
                if (inDegree[eachCourse] == 0)
                    courseQueue.push(eachCourse);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] != 0) 
                return false;
        }
        return true;
    }
};

int main()
{
    int numCourses = 2;
    //vector<vector<int>> prerequisites = {
    //    {1, 0},
    //    {2, 1},
    //    {3, 2},
    //    {4, 1},
    //    {3, 4}
    //};
    vector<vector<int>> pre = { {1, 0} };
    Solution sol;
    if (sol.canFinish(numCourses, pre))
        cout << "YES\n";
    else
        cout << "No\n";
}