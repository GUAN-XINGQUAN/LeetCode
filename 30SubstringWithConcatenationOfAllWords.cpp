#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		// No string or no words => return nothing
		if (s.size() == 0 || words.empty())
			return {};

		vector<int> res;

		// Put words into a Hash table
		int n = words.size(), len = words[0].size();
		unordered_map<string, int> dict;
		for (string str : words)
		{
			if (dict.find(str) == dict.end())
				dict[str] = 1;
			else
				dict[str]++;
		}
		// Loop over te whole string to see if the words are covered by string
		for (int i = 0; i <= (static_cast<int>(s.size()) - n * len); i++)
		{
			unordered_map<string, int> strCount;
			int j = 0;
			for (j = 0; j < n; j++)
			{
				string target = s.substr(i + j * len, len);
				if (dict.find(target) == dict.end())
					break;
				if (strCount.find(target) == strCount.end())
					strCount[target] = 1;
				else
					strCount[target]++;
				if (strCount[target] > dict[target])
					break;
			}
			if (j == n) res.push_back(i);
		}
		return res;
	}
};

int main()
{
	string s = "wordgoodgoodgoodbestword";
	vector<string> words = { "word", "good", "best", "good" };
	Solution sol;

	vector<int> res = sol.findSubstring(s, words);

	vector<int>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << '\t';
		it++;
	}
}