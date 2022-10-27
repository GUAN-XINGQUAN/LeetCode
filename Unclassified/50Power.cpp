#include <iostream>
using namespace std;

// Method 1: Brute force, using for loop.
//class Solution
//{
//public:
//	double myPow(double x, int n)
//	{
//		double returnValue = 1.0;
//		int N = n;
//		if (n < 0)
//			N = -1 * n;
//		for (int k = 0; k < N; k++)
//			returnValue *= x;
//		if (n < 0)
//			returnValue = 1 / returnValue;
//		return returnValue;
//	}
//};

// Method 2: recursive method
class Solution
{
public:
	double myPow(double x, int n)
	{
		if (n < 0)
			return 1.0 / power(x, -n);
		else
			return power(x, n);
	}
	double power(double x, int n)
	{
		if (n == 0)
			return 1.0;
		double half = power(x, int(n / 2));
		if (n % 2 == 0)
			return half * half;
		else
			return half * half*x;
	}
};


int main()
{
	double xx = 2;
	int nn = 3;
	Solution sol;
	cout << sol.myPow(xx, nn);
}