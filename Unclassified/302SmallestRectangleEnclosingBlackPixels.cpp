#include <iostream>
#include<vector>
#include<cassert>
#include<queue>

using namespace std;


/*
solution 1:
    1. loop over each black pixels
    2. find the boundary of the black pixels
    3. calculate the area
    time complexity: O(m*n)
    space complexity: O(1)
*/
class Solution1 {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // no edge case since 1<= m, n <= 100
        int m = image.size(), n = image[0].size();
        int left = n, right = 0, up = m, bot = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (image[i][j] == '0')
                    continue;
                left = min(j, left);
                right = max(j + 1, right);
                up = min(i, up);
                bot = max(i + 1, bot);
            }
        }
        // cout << left << '\t' << right << endl;
        // cout << up << '\t' << bot << endl;
        int area = (right - left) * (bot - up);
        return area;
    }
};

/*
solution 2:
    1. starting from the given location
    2. use BFS to traverse each black pixel
    3. update the coordinate
    4. calculate the area
    time complexity: O(B)
    space complexity: O(B)
*/
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = n, right = 0, up = m, bot = 0;
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // four directions
        vector<vector<bool>> visited (m, vector<bool> (n, false));   // track the visited spot
        queue<int> locationQueue({ x * n + y });
        visited[x][y] = true;
            // BFS
            while (!locationQueue.empty())
            {
                int tempLoc = locationQueue.front();
                locationQueue.pop();
                int curX = tempLoc / n, curY = tempLoc % n;
                left = min(curY, left);
                right = max(curY + 1, right);
                up = min(curX, up);
                bot = max(curX + 1, bot);
                // adjacent locations
                for (auto eachDir : directions)
                {
                    int nextX = curX + eachDir[0], nextY = curY + eachDir[1];
                    if (isValid(nextX, nextY, m, n, image, visited))
                    {
                        locationQueue.push(nextX * n + nextY);
                        visited[nextX][nextY] = true;
                    }
                }
            }
        int area = (bot - up) * (right - left);
        return area;
    }
    bool isValid(int x, int y, int m, int n, vector<vector<char>>& image, vector<vector<bool>>& visited)
    {
        if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == '1' && visited[x][y] == false)
            return true;
        return false;
    }
};


int main()
{
    vector<vector<char>> image = { {'0', '0', '1', '0'},{'0', '1', '1', '0'},{'0', '1', '0', '0'} };
    int x = 0, y = 2;
    Solution sol;
    int area = sol.minArea(image, x, y);
    assert(area == 6);
    cout << "Test passed\n";
}