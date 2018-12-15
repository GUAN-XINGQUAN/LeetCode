#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1:
//bool compare(string a, string b)
//{
//	if (a.size() == b.size())
//		return a < b;
//	return a.size() > b.size();  // Descending order
//}

//class Solution
//{
//public:
//	string findLongestWord(string s, vector<string>& d)
//	{
//		sort(d.begin(), d.end(), compare);
//		for (string currentStr : d)
//		{
//			size_t i = 0;
//			for (char c : s)
//			{
//				if (i < currentStr.size() && c == currentStr[i])
//					i++;
//			}
//			if (i == currentStr.size())
//				return currentStr;
//		}
//		return "";
//	}
//};

// Method 2:
class Solution
{
public:
	string findLongestWord(string s, vector<string> &d)
	{
		string returnValue = "";
		for (string currentStr : d)
		{
			size_t i = 0;
			for (char c : s)
			{
				if (i < currentStr.size() && c == currentStr[i])
					i++;
			}
			if (i == currentStr.size())
			{
				if (currentStr.size() > returnValue.size())
					returnValue = currentStr;
				else if (currentStr.size() == returnValue.size() && currentStr < returnValue)
					returnValue = currentStr;
			}
		}
		return returnValue;
	}
};

int main()
{
	string s = "abpcplea";
	vector<string> d(4);
	d[0] = "a";
	d[1] = "b";
	d[2] = "c";
	d[3] = "p";
	Solution sol;
	cout << sol.findLongestWord(s, d) << endl;
	for (int k = 0; k != d.size(); k++)
		cout << d[k] << endl;
}