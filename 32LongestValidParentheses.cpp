#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int res = 0, start = 0;
		stack<int> st;
		for (int i = 0; i < static_cast<int>(s.size()); i++)
		{
			if (s[i] == '(')
				st.push(i);
			if (s[i] == ')')
			{
				if (st.empty())
					start = i + 1;
				else
				{
					st.pop();
					if (st.empty())
						res = max(res, i - start + 1);
					else
						res = max(res, i - st.top());
				}
			}
		}
		return res;
	}
};

int main()
{
	string s = "()()";
	Solution sol;

	int res = sol.longestValidParentheses(s);

	cout << res;
}