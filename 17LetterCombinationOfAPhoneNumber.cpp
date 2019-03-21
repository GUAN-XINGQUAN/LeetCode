#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> em = {};
		if (digits.size() == 0)
			return em;
		unordered_map<int, string> mp;
		int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		string arr2[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (int i = 0; i <= 9; i++)
			mp[arr1[i]] = arr2[i];
		vector<string> res = { "" };
		for (unsigned i = 0; i != digits.size(); i++)
		{
			vector<string> temp;
			string tempStr = mp[digits[i] - '0'];
			for (unsigned j = 0; j != tempStr.size(); j++)
			{
				for (string s:res)
				{
					temp.push_back(s + tempStr[j]);
				}
			}
			res = temp;
		}
		return res;
	}
};

int main()
{
	string digits = "23";
	Solution sol;
	vector<string> res = sol.letterCombinations(digits);
	vector<string>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << endl;
		it++;
	}
}