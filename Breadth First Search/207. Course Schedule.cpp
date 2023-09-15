/*
This is a topological sort problem. We can solve it with BFS.

1. Convert the problem inputs to a graph and count in-degree for each node
2. Start with zero in-degree node and trace each node with BFS
   When we reach to a node, we reduce that node in-degree by 1.
3. Once we finish all nodes, check if there exist any non-zero in-degree node. If so, there is a cycle. Otherwise, no cycle.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        queue<int> courseQueue;
        // start with zero in-degree nodes
        for (unordered_map<int, int>::iterator it = nodeDegree.begin(); it != nodeDegree.end(); it++)
        {
            int node = it->first, degree = it->second;
            if (degree == 0)
                courseQueue.push(node);
        }
        // BFS to search all neighbors
        int countNode = 0;
        while(!courseQueue.empty())
        {
            int cur = courseQueue.front(); courseQueue.pop();
            countNode++;
            for (int j = 0; j < graph[cur].size(); j++)
            {
                if (--nodeDegree[graph[cur][j]] == 0)
                    courseQueue.push(graph[cur][j]);
            }
        }
        return countNode == numCourses ? true : false;
    }
};