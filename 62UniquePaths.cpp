#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		// Initialize a 2D array to store the dynamic programming result
		vector<vector<int>> path(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}
		return path[m-1][n-1];
	}
};

int main()
{
	int m = 7, n = 3;
	Solution sol;
	int result = sol.uniquePaths(m, n);
	cout << "the result is: " << result << endl;
}