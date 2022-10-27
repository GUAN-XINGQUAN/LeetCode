#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
	void reverseString(vector<char>& s) 
	{
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			++left;
			--right;
		}
	}
};



int main()
{
	Solution sol;
	char vec[] = { 'h','e','l','l','o' };
	vector<char> s;
	for (int i = 0; i != 5; i++)
		s.push_back(vec[i]);
	sol.reverseString(s);
	for (int i = 0; i != 5; i++)
		cout << s[i] << endl;
}