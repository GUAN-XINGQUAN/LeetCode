#include <iostream>
#include <string>

using namespace std;

// Method 1: Brute force
//class Solution {
//public:
//	int lengthOfLastWord(string s) {
//		int size = s.size()-1;
//		int count = 0;
//		for (int i = size; i >= 0; i--)
//		{
//			if (s[i] != ' ')
//				count++;
//			else if (count > 0)
//				break;
//		}
//		return count;
//	}
//};

// Method 2: remove spaces at end of the string
class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0, right = s.size() - 1;
		while (s[right] == ' ' && right >= 0)
			right--;
		while (s[right] != ' ' && right >= 0)
		{
			count++;
			right--;
		}
		return count;
	}
};



int main()
{
	Solution sol;
	string s = "Hello World";
	int result = sol.lengthOfLastWord(s);
	cout << "The length of last word is: " << result << endl;
}