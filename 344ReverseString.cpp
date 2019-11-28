#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			swap(s[left++], s[right--]);
		}

	}
};


int main()
{
	vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
	Solution sol;
	sol.reverseString(s);

	// Display the result
	vector<char>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << '\t';
		it++;
	}
}