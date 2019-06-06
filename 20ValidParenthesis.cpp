#include <string>
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (unsigned i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case '(':
			case '[':
			case '{':
				st.push(s[i]);
				break;
			case ')':
				if (st.empty() || st.top() != '(')
					return false;
				st.pop();
				break;
			case ']':
				if (st.empty() || st.top() != '[')
					return false;
				st.pop();
				break;
			case '}':
				if (st.empty() || st.top() != '{')
					return false;
				st.pop();
				break;
			}
		}
		if (!st.empty())
			return false;
		return true;
	}
};


int main()
{
	Solution sol;
	string str1 = "{[]}";
	string str2 = "[][";
	string str3 = "123][";
	string str4 = "[()]{{{";
	assert(sol.isValid(str1));
	assert(!sol.isValid(str2));
	assert(!sol.isValid(str3));
	assert(!sol.isValid(str4));
	cout << "All tests passed!" << endl;
}