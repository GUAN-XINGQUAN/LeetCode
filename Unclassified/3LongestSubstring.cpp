#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int left = -1, result = 0;
		unordered_map<int, int> mp;
		unsigned i = 0;
		while (i < s.size())
		{
			unordered_map<int, int>::iterator it = mp.find(s[i]);
			if (it != mp.end() && mp[s[i]] > left)
				left = mp[s[i]];
			if (int(i) - left > result)
				result = i - left;
			mp[s[i]] = i;
			i++;
		}
		return result;
	}
};

int main()
{
	string str = "abba";
	Solution sol;
	int result = sol.lengthOfLongestSubstring(str);
	cout << result << endl;
}