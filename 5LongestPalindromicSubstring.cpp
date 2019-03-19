#include <iostream>
#include <string>

using namespace std;

// Time complexity O(N^2)
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1)
			return s;
		int start(0), maxLength(0);
		for (int i = 0; i != s.size(); i++)
		{
			searchPalindrome(s, i, i, start, maxLength);
			searchPalindrome(s, i, i + 1, start, maxLength);
		}
		return s.substr(start, maxLength);
	}
	void searchPalindrome(string s, int left, int right, int& start, int& maxLength)
	{
		while (left >= 0 && right < static_cast<int>(s.size()) && left <= right && s[left] == s[right])
		{
			left--;
			right++;
		}
		if (maxLength < right - left - 1)
		{
			maxLength = right - left - 1;
			start = left+1;
		}
	}
};

int main()
{
	Solution sol;
	string str = "babad";
	string res = sol.longestPalindrome(str);
	cout << res << endl;
}