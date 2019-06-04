#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs) 
	{
		if (strs.size() == 0)
			return "";
		string result = "";
		for (unsigned i = 0; i < strs[0].length(); i++)
		{
			char ch = strs[0][i];
			for (unsigned j = 0; j < strs.size(); j++)
			{
				if (i >= strs[j].length())
					return result;
				if (strs[j][i] != ch)
					return result;
			}
			result += ch;
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<string> vec = { "flower", "flow", "flight" };
	string answer = sol.longestCommonPrefix(vec);
	cout << answer << endl;
}
