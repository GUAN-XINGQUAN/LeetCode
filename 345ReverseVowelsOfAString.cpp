#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseVowels(string s)
	{
		int first = 0;
		int last = s.size();
		while (first < last)
		{
			if (isVowels(s[first]) && isVowels(s[last]))
			{
				char temp = s[first];
				s[first] = s[last];
				s[last] = temp;
				first++;
				last--;
			}
			else if (isVowels(s[first]))
				last--;
			else
				first++;
		}
		return s;
	}
	bool isVowels(char c)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			return true;
		else
			return false;
	}
};

int main()
{
	string str = "hello";
	Solution sol;
	cout << sol.reverseVowels(str) << endl;
}