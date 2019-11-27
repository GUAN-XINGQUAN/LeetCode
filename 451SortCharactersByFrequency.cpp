#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Reload the comparator
bool comparePairs(const pair<char, int>& p1, const pair<char, int>& p2)
{
	return p1.second > p2.second;
}

// Using Cpp HashTable would be much easier!
class Solution
{
public:
	string frequencySort(string s) {
		string result;
		unordered_map<char, int> mp;
		// Count the number of each character
		for (char each : s)
		{
			unordered_map<char, int>::iterator it = mp.find(each);
			if (it == mp.end())
				mp[each] = 1;
			else
				mp[each] += 1;
		}
		vector<pair<char, int>> vec(mp.begin(), mp.end());
		sort(vec.begin(), vec.end(), comparePairs);
		for (unsigned i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].second; j++)
			{
				result += vec[i].first;
			}
		}
		return result;
	}
};

// Test
int main()
{
	string s = "tree";
	Solution sol;
	string result = sol.frequencySort(s);
	cout << "The result is: " << result << endl;
}