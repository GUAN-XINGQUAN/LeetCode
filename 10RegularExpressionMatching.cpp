#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// Approach 1: recursion
class Solution1 {
public:
	bool isMatch(string s, string p) {
		// Base case: empty p
		if (p.size() == 0)
			return (s.size() == 0);
		// Base case: p has only one char
		if (p.size() == 1)
			return (s.size() == 1 && (p == s || p == "."));
		// More complicated case: p has more than one char
		if (p[1] != '*')
			if (s.size() == 0)
				return false;
			else if (s[0] == p[0] || p[0] == '.')
				return isMatch(s.substr(1), p.substr(1));
			else
				return false;
		else
		{
			while (s.size() != 0 && (s[0] == p[0] || p[0] == '.'))
			{
				if (isMatch(s, p.substr(2)))
					return true;
				s = s.substr(1);
			}
		}
		return isMatch(s, p.substr(2));
	}
};


// Dynamic programing
// 
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> DP(m + 1, vector<bool>(n + 1, false));
		DP[0][0] = true;

		for (int i = 0; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j > 1 && p[j - 1] == '*')
				{
					DP[i][j] = DP[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) && DP[i - 1][j];
				}
				else
				{
					DP[i][j] = (i > 0) && DP[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
			}
		}
		return DP.back().back();
	}
};

int main()
{
	string s = "mississippi";
	string p = "mis*is*p*.";
	Solution sol;

	if (sol.isMatch(s, p))
		cout << "Match\n";
	else
		cout << "No\n";
}