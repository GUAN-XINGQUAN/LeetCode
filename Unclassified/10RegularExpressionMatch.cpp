#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		// Base case: empty p
		if (p.size() == 0)
			return (s.size() == 0);
			// Base case: p has only one char
		if (p.size() == 1)
			return (s.size() == 1 && (p == s || p == "."));
		// More complicated case: p has more than one char
		if (p[1] != '*')
			if (s.size() == 0)
				return false;
			else if (s[0] == p[0] || p[0] == '.')
				return isMatch(s.substr(1), p.substr(1));
			else
				return false;
		else
		{
			while (s.size() != 0 && (s[0] == p[0] || p[0] == '.'))
			{
				if (isMatch(s, p.substr(2)))
					return true;
				s = s.substr(1);
			}
		}
		return isMatch(s, p.substr(2));
	}
};

int main()
{
	string s = "mississippi";
	string p = "mis*is*p*.";
	Solution sol;

	assert(!sol.isMatch(s, p));

	cout << "Passed!!!\n";
	

	
}