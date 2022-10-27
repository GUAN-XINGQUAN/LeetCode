#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// User defined function to visualize 2D array.
#include "NestedVectorIntVisualization.h"

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {      
        // store the course as a graph and nodes' in degree.
        // data structure for graph: parent node -> child node.
        // data structure for inDegree: each node -> in degree.
        vector<vector<int>> graph(numCourses, vector<int> {});
        vector<int> inDegree(numCourses, 0);
        for (auto each : prerequisites)
        {
            graph[each[1]].push_back(each[0]);
            ++inDegree[each[0]];
        }

        // Store all nodes with zero in degree into queue.
        queue<int> nodeQueue;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
                nodeQueue.push(i);
        }

        // BFS
        vector<int> res;
        while (!nodeQueue.empty())
        {
            int tempNode = nodeQueue.front();
            nodeQueue.pop();
            res.push_back(tempNode);
            for (auto eachChild : graph[tempNode])
            {
                --inDegree[eachChild];
                if (inDegree[eachChild] == 0)
                    nodeQueue.push(eachChild);
            }
        }

        // Consider all cases
        if (res.size() != numCourses)
            res.clear();
        return res;
    }
};

int main()
{
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2},
        {4, 1},
        {3, 4}
    };
    int numCourses = 5;

    Solution sol;

    vector<int> res = sol.findOrder(numCourses, prerequisites);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}