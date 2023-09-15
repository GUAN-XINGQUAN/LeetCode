/*
This is similar to 490. The Maze. The only difference is that this problem asks us to return the shortest distance (not the number of movements).
When asked the shortest distance in the graph, we always strated with BFS or Dijkstra algorithm.
The difference between BFS and Dijkstra is the moment when we want to make next movement:
(1) BFS just explores all directions with equal probability
(2) Dijkstra explores the next movement with shortest current distance (not the global smallest distance).

1. Create a 2D array to store the distance to each spot and initialized each cell as MAX
2. Mark the distance to starting spot as zero.
3. Run Dijkstra algorithm:
   Use priority_queue to replace queue in BFS
   Meanwhile, no need to use a 2D boolean array to mark which cell has been visited and which has not because the priority_queue tentatively explores the most recent cell. Any "revisting path" is longer than the one calcaulated at the prioirty_queue firstly pops the cell.

*/

struct compare {
    bool operator()(vector<int>& vec1, vector<int>& vec2)
    {
        // we want smaller distance pops out first (right end), so large distance goes to left
        return vec1.back() > vec2.back();
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // preparation
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int nRows = maze.size(), nCols = maze[0].size();
        vector<vector<int>> distance (nRows, vector<int> (nCols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, compare> spotDistance;
        spotDistance.push({start[0], start[1], 0});
        distance[start[0]][start[1]] = 0;

        // Dijkstra algorithm
        while (!spotDistance.empty())
        {
            int size = spotDistance.size();
            // we don't need this by-layer for loop in this problem statement
            //for (int i = 0; i < size; i++)
            //{
                vector<int> cur = spotDistance.top(); spotDistance.pop();
                for (int j = 0; j < 4; j++)
                {
                    int result = 0;
                    // make next movement
                    int x = cur[0] + dirs[j][0];
                    int y = cur[1] + dirs[j][1];
                    result++;
                    // keep moving until we hit the wall
                    while (x >= 0 && x < nRows && y >= 0 && y < nCols && maze[x][y] == 0)
                    {
                        x += dirs[j][0];
                        y += dirs[j][1];
                        result++;
                    }
                    // after while loop, we are at the wall; take one step back
                    x -= dirs[j][0];
                    y -= dirs[j][1];
                    result--;
                    // Compare distance
                    if (distance[cur[0]][cur[1]] + result < distance[x][y])
                    {
                        distance[x][y] = distance[cur[0]][cur[1]] + result;
                        spotDistance.push({x, y, distance[x][y]});
                    }
                }
            //}
        }
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};