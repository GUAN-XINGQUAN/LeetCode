#include <iostream>
#include <string>
using namespace std;
// Method 1: Brute force
// Time: O(N^2); Space: O(1);
//bool isUnique(string str)
//{
//	for (int i = 0; i != str.size()-1; i++)
//	{
//		for (int j = i + 1; j != str.size(); j++)
//		{
//			if (str[j] == str[i])
//				return false;
//		}
//	}
//	return true;
//}

// Method 2:
// Assume it is ASCII string and assume there are 128 different characters in total
bool isUnique(string str)
{
	if (str.size() > 128)  // If the string includes more than 128 characters 
		return false;  // there must be repeated characters


}

int main()
{
	string s = "abcdefa";
	if (isUnique(s))
		cout << "Unique!" << endl;
	else
		cout << "Not unique!" << endl;
}