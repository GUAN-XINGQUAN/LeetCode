#include<iostream>
#include<string>
#include<set>

using namespace std;

// Method 1: use STL set
//class Solution {
//public:
//	string reverseVowels(string s) {
//		set<char> st = { 'a', 'e', 'i', 'o', 'u', 'A' ,'E', 'I', 'O', 'U'};
//		int left = 0, right = s.size() - 1;
//		while (left < right)
//		{
//			if (st.count(s[left]) == 0)
//				left++;
//			else if (st.count(s[right]) == 0)
//				right--;
//			else
//				swap(s[left++], s[right--]);
//		}
//		return s;
//	}
//};

// Method 2: use user-defined isVowel function
class Solution
{
public:
	string reverseVowels(string s)
	{
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			if (isVowels(s[left]) && isVowels(s[right]))
			{
				char temp = s[left];
				s[left] = s[right];
				s[right] = temp;
				left++, right--;
			}
			else if (isVowels(s[left]) && !isVowels(s[right]))
				right--;
			else if (!isVowels(s[left]) && isVowels(s[right]))
				left++;
			else
			{
				left++, right--;
			}
		}
		return s;
	}
	bool isVowels(char ch)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
			ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			return true;
		else
			return false;
	}

};

int main()
{
	Solution sol;
	string s = "hello";
	string result = sol.reverseVowels(s);

	cout << "The result is: " << result << endl;
}