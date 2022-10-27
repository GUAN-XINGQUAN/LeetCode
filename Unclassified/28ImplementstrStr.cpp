#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int a = haystack.size();
		int b = needle.size();
		if (a < b)
			return -1;
		for (int i = 0; i <= a-b; i++)
		{
			int j = 0;
			for (; j != b; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == b)
				return i;
		}
		return -1;
	}
};

int main()
{
	string str1 = "ABCDE";
	string str2 = "";
	Solution sol;
	cout << sol.strStr(str1, str2) << endl;
}