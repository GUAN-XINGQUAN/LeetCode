#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) 
	{
		int left = n, right = n;
		string parenthesis;
		vector<string> res;
		generateParenthesisHelper(left, right, parenthesis, res);
		return res;
	}
	void generateParenthesisHelper(int left, int right, string parenthesis, vector<string> &res)
	{
		if (left > right)
			return;
		if (left == 0 && right == 0)
		{
			res.push_back(parenthesis);
			return;
		}
		if (left > 0)
			generateParenthesisHelper(left - 1, right, parenthesis + '(', res);
		if (right > 0)
			generateParenthesisHelper(left, right - 1, parenthesis + ')', res);
	}
};

int main()
{
	int n = 2;
	Solution sol;
	vector<string> res = sol.generateParenthesis(n);
	vector<string>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << endl;
		it++;
	}
}