#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		int first = 0;
		int last = s.size() - 1;
		while (first < last)
		{
			if (!isLetterNum(s[first]))
				first++;
			else if (!isLetterNum(s[last]))
				last--;
			else if (tolower(s[first]) != tolower(s[last]))
				return false;
			else
			{
				first++;
				last--;
			}
		}
		return true;
	}
	bool isLetterNum(char c)
	{
		if (isalpha(c) || isdigit(c))
			return true;
		else
			return false;
	}
};

int main()
{
	string str = "A man a plan a canal : Panama";
	Solution sol;
	cout << sol.isPalindrome(str) << endl;
}