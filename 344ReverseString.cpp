#include <iostream>
#include <string>
using namespace std;


class Solution
{
public:
	string reverseString(string s)
	{
		int first = 0;
		int last = s.size()-1;
		while (first < last)
		{
			char temp = s[first];
			s[first] = s[last];
			s[last] = temp;
			first++;
			last--;
		}
		return s;
	}
};

int main()
{
	string str = "hello";
	Solution sol;
	cout << sol.reverseString(str);
}

