#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.size() == 0)
			return 0;
		int i = 0;
		while (i < static_cast<int>(str.size()) && str[i] == ' ')
			i++;
		int sign;
		if (isdigit(str[i]))
			sign = 1;
		else if (str[i] == '+')
		{
			sign = 1;
			i++;
		}
		else if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else
			return 0;
		int base(0);
		int index = i;
		while (index < static_cast<int>(str.size()) && isdigit(str[index]))
		{
			if (base > INT_MAX / 10 || ((base == INT_MAX / 10) && (str[index]-'0' > 7 )))
			{
				if (sign == 1)
					return INT_MAX;
				else
					return INT_MIN;
			}
			base = 10 * base + (str[index] - '0');
			index++;
		}
		return base * sign;
	}
};

int main()
{
	string str = "-2147483648";
	Solution sol;
	// cout << INT_MIN << endl;
	// cout << INT_MAX << endl;
	int res = sol.myAtoi(str);
	cout << res << endl;
	
}