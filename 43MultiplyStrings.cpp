#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int n1 = num1.size(), n2 = num2.size();
		vector<int> num(n1 + n2);
		string s = "";
		for (int i = n1 - 1; i >= 0; i--)
		{
			for (int j = n2 - 1; j >= 0; j--)
			{
				int multi = (num1[i] - '0') * (num2[j] - '0');
				int d1 = i + j, d2 = i + j + 1;  // d2 is the right digit, d1 is the left digit
				int sum = multi + num[d2];
				num[d1] += sum / 10;
				num[d2] = sum % 10;
			}
		}
		for (int each : num)
		{
			// If leading is zero. Do nothing.
			if (s != "" || each != 0)
				s.push_back(each + '0');
		}
		if (s == "")
			return "0";
		else
			return s;
	}
};

int main()
{
	Solution sol;
	string num1 = "123", num2 = "456";
	string res = sol.multiply(num1, num2);
	cout << res << endl;
	
}