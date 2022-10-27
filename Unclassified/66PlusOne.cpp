#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		for (int k = digits.size() - 1; k >= 0; k--)
		{
			if (digits[k] != 9)
			{
				digits[k] += 1;
				return digits;
			}
			else
			{
				digits[k] = 0;
			}
		}
		if (digits[0] == 0)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	Solution sol;
	vector<int> dig = { 9, 9, 9 };
	vector<int> result = sol.plusOne(dig);
	for (int k = 0; k != result.size(); k++)
		cout << result[k] << endl;
}