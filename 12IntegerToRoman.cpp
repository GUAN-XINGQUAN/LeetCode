#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		vector<char> roman = {  'M', 'D', 'C', 'L', 'X', 'V', 'I' };
		vector<int> number = { 1000, 500, 100, 50, 10, 5, 1 };
		string res = "";
		for (int i = 0; i < 7; i+=2)
		{
			int remainder = num / number[i];
			int a = number[i];
			switch (remainder)
			{
			case 0:
			case 1:
			case 2:
			case 3:
				for (int j = 0; j != remainder; j++)
					res += roman[i];
				break;
			case 4:
				res = res + roman[i] + roman[i-1];
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				res = res + roman[i - 1];
				for (int j = 6; j <= remainder; ++j) 
					res += roman[i];
				break;
			case 9:
				res = res + roman[i] + roman[i-2];
				break;
			}
			num = num % number[i];
		}
		return res;
	}
};


int main()
{
	int num = 1994;
	Solution sol;
	string s = sol.intToRoman(num);
	cout << s << endl;

}