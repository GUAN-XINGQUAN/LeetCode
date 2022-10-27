#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, int> map;
		for (unsigned i = 0; i < strs.size(); i++)
		{
			string str = strs[i];
			sort(str.begin(), str.end());
			if (map.count(str) == 0)
			{
				map[str] = result.size();
				result.push_back({});
			}
			result[map[str]].push_back(strs[i]);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> result = sol.groupAnagrams(strs);
	// Two way to iterate through the vector
	// Use iterator
	vector<vector<string>>::iterator outIT = result.begin();
	while (outIT != result.end())
	{
		vector<string>::iterator innerIT = (*outIT).begin();
		while (innerIT != (*outIT).end())
		{
			cout << *innerIT << ' ';
			innerIT++;
		}
		cout << endl;
		outIT++;
	}
	// Use index
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (int j = 0; j < result[i].size(); j++)
	//		cout << result[i][j] << '\t';
	//	cout << endl;
	//}
}