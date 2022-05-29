// BFS: time limit exceed
class Solution1 {
public:  
    int move[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    int minKnightMoves(int x, int y) {
        queue<pair<int, int>> nodeQueue;
        nodeQueue.push({0, 0});
        
        set<pair<int, int>> nodeSet;
        nodeSet.insert({0, 0});
        
        int steps = 0;
        
        while (!nodeQueue.empty())
        {
            int n = nodeQueue.size();
            for (int i = 0; i < n; i++)
            {
                pair<int, int> curNode = nodeQueue.front();
                nodeQueue.pop();
                if (curNode.first == x && curNode.second == y)
                    return steps;
                
                for (auto eachMove : move)
                {
                    int nextX = curNode.first + eachMove[0];
                    int nextY = curNode.second + eachMove[1];
                    if (nodeSet.count({nextX, nextY}) == 0)
                    {
                        nodeSet.insert({nextX, nextY});
                        nodeQueue.push({nextX, nextY});
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};

// BFS: use vector to store the visited spots
class Solution {
public:  
    int move[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    int minKnightMoves(int x, int y) {
        queue<pair<int, int>> nodeQueue;
        nodeQueue.push({0, 0});
        
        vector<vector<bool>> visited (700, vector<bool> (700, false));
        visited[350][350] = true;   // see the constraints
        
        int steps = 0;
        
        while (!nodeQueue.empty())
        {
            int n = nodeQueue.size();
            for (int i = 0; i < n; i++)
            {
                pair<int, int> curNode = nodeQueue.front();
                nodeQueue.pop();
                if (curNode.first == x && curNode.second == y)
                    return steps;
                
                for (auto eachMove : move)
                {
                    int nextX = curNode.first + eachMove[0];
                    int nextY = curNode.second + eachMove[1];
                    if (visited[nextX+350][nextY+350] == false)
                    {
                        visited[nextX+350][nextY+350] = true;
                        nodeQueue.push({nextX, nextY});
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};
