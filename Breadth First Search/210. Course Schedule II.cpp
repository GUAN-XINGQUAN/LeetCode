/*
This is similar to 207. Course Schedule. The only difference is that we need to store the path.

Based on solution to 207, we just need to add an array to store the result.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // convert input to a graph; we can also use vectors to store degree and graph
        unordered_map<int, int> nodeDegree;  // node -> in-degree
        unordered_map<int, vector<int>> graph;  // adjacent list: node and its neighbors
        // initialize nodeDegree and graph
        for (int i = 0; i < numCourses; i++)
        {
            nodeDegree[i] = 0;  // no in-degree
            graph[i] = {};  // empty neighbor list
        }
        for (int i = 0; i < prerequisites.size(); i++)
        {
            // count in-degree
            nodeDegree[prerequisites[i][0]] += 1;  
            // save adjacent nodes with direction
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // BFS with topological sort
        vector<int> result;
        queue<int> courseQueue;
        // start with zero in-degree nodes
        for (unordered_map<int, int>::iterator it = nodeDegree.begin(); it != nodeDegree.end(); it++)
        {
            int node = it->first, degree = it->second;
            if (degree == 0)
            {
                courseQueue.push(node);
            }
        }
        // BFS to search all neighbors
        while(!courseQueue.empty())
        {
            int cur = courseQueue.front(); courseQueue.pop();
            result.push_back(cur);
            for (int j = 0; j < graph[cur].size(); j++)
            {
                if (--nodeDegree[graph[cur][j]] == 0)
                {    
                    courseQueue.push(graph[cur][j]);
                }
            }
        }
        return result.size() == numCourses ? result : vector<int> {};
    }
};