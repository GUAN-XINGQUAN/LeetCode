#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> out;
		int start = 0;
		PalindromeHelper(s, start, out, res);
		return res;
	}
	void PalindromeHelper(string s, int start, vector<string>& out, vector <vector<string>>& res)
	{
		if (start == s.size())
			res.push_back(out);
		for (int i = start; i < s.size(); i++)
		{
			if (!isPanlindrome(s, start, i))
				continue;
			out.push_back(s.substr(start, i - start + 1));
			PalindromeHelper(s, i + 1, out, res);
			out.pop_back();
		}
	}
	bool isPanlindrome(string s, int start, int end)
	{
		while (start < end)
		{
			if (s[start] != s[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
};

int main()
{
	string s = "aab";
	Solution sol;
	vector<vector<string>> res = sol.partition(s);
	vector<vector<string>>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << "------------------\n";
		vector<string>::iterator itt = it->begin();
		while (itt != it->end())
		{
			cout << *itt << '\t';
			itt++;
		}
		cout << "\n";
		it++;
	}
}