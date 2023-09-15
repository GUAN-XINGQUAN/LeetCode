#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct compare
{
	bool operator()(vector<int>& vec1, vector<int>& vec2)
	{
		// vec1 & vec2: {x, y, distance}
		// I want smaller distance to have higher priority
		return vec1.back() > vec2.back();
	}
};

int dijkstra(vector<vector<int>>& maze, vector<int>& start, vector<int>& end)
{
	// maze is a valid 2D array representing a weighted graph
	// start contains X and Y for the start location
	// end contains X and Y for the destination
	// assume that all input arguments are ensured to be valid and not ill-defined

	// preparation
	int nRows = maze.size(), nCols = maze[0].size();
	vector<vector<int>> distance(nRows, vector<int>(nCols, INT_MAX));
	priority_queue<vector<int>, vector<vector<int>>, compare> locationDistance;
	locationDistance.push({ start[0], start[1], maze[start[0]][start[1]]});
	int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	// Dijkstra algorithm
	while (!locationDistance.empty())
	{
		vector<int> cur = locationDistance.top(); locationDistance.pop();
		for (int j = 0; j < 4; j++)
		{
			// make next movement
			int nextX = cur[0] + dirs[j][0];
			int nextY = cur[1] + dirs[j][1];
			int cost = cur[2];

			// check if movement is valid
			if (nextX >= 0 && nextX < nRows && nextY >= 0 && nextY < nCols)
			{
				cost = cost + maze[nextX][nextY];

				// distance comparison: only update the distance if we have shorter path
				if (cost < distance[nextX][nextY])
				{
					distance[nextX][nextY] = cost;
					locationDistance.push({ nextX, nextY, cost });
				}
			}
		}
	}
	return distance[end[0]][end[1]] == INT_MAX ? -1 : distance[end[0]][end[1]];
}


int main()
{
	vector<vector<int>> grid = {
		{1, 1, 1},
		{0, 5, 1},
		{0, 0, 1}
	};

	vector<int> start = { 0, 0 };
	vector<int> end = { 2, 2 };

	cout << dijkstra(grid, start, end) << endl;
}