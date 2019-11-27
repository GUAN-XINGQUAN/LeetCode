#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
	int addDigits(int num) 
	{
		int result = 10;
		while (result > 9)
		{
			result = addHelper(num);
			num = result;
		}
		return result;

	}
	int addHelper(int num)
	{
		int sum = 0;
		int remainder, dev = 1;
		while (dev != 0)
		{
			remainder = num % 10;
			dev = num / 10;
			sum += remainder;
			num = dev;
		}
		return sum;
	}
};

int main()
{
	Solution sol;
	int num1 = 38;
	int num2 = 198;
	int num3 = 0;

	int result1 = sol.addDigits(num1);
	int result2 = sol.addDigits(num2);
	int result3 = sol.addDigits(num3);
	
	assert(result1 == 2);
	assert(result2 == 9);
	assert(result3 == 0);

	cout << "All tests passed!\n";
}