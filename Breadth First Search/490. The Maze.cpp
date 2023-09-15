/*
This is a typical BFS problem.
The only nuance here is that instead of moving "one level/layer at a time", we need to move until we hit the wall.
In this case, we can convert "moving many steps to hit the wall" as "one layer" in BFS by using a while loop like below:
    while (within the maze and do not hit the wall)
    {
        keep moving X and Y in the designated direction;
    }
    return the next X and Y, which will be our next spot after "one layer movement".
Then the rest of the problem can be solved using the BFS template.
*/


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // four directions
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // BFS on 2D array application
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        queue<vector<int>> spotQueue ({start});
        visited[start[0]][start[1]] = true;
        while (!spotQueue.empty())
        {
            int size = spotQueue.size();
            // we can remove the "by tier" for loop because we don't need to count steps
            // for (int i = 0; i < size; i++)
            // {
                vector<int> cur = spotQueue.front(); spotQueue.pop();
                if (cur == destination)
                    return true;
                // four direction movement
                for (int j = 0; j < 4; j++)
                {
                    // make one step movement
                    int x = cur[0] + dirs[j][0], y = cur[1] + dirs[j][1];
                    // convert "keep moving until hitting the wall" to "one step movement"
                    while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
                    {
                        x = x + dirs[j][0];
                        y = y + dirs[j][1];
                    }
                    // when while breaks, we already hit the wall, so we revert back to the last valid location
                    x = x - dirs[j][0];
                    y = y - dirs[j][1];
                    if (visited[x][y] == false)
                    {
                        spotQueue.push({x, y});
                        visited[x][y] = true;
                    }
                }
            // }
        }
        return false;
    }
};