#include<iostream>
#include<cmath>

using namespace std;

// Use bit operation (not recommended) (hard to understand)
class Solution1 {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		long m = labs(dividend), n = labs(divisor), sign = 1, res = 0;
		if ((dividend > 0) ^ (divisor > 0))
			sign = -1;
		while (m >= n)
		{
			long t = n, p = 1;
			while (m >= (t << 1))
			{
				t = t << 1;
				p = p << 1;
			}
			res += p;
			m -= t;
		}

		if (sign == 1)
			return res;
		else
			return -res;
	}
};

// Use Brute Force (not recommended)
class Solution2 {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN)
		{
			if (divisor == -1)
				return INT_MAX;
			if (divisor == 1)
				return INT_MIN;
		}
		
		long tempDividend = labs(dividend), tempDivisor = labs(divisor), count = 0;
		cout << tempDividend << endl;
		cout << tempDivisor << endl;
		while (tempDividend >= tempDivisor)
		{
			count++;
			tempDividend -= tempDivisor;
		}
		
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			return -count;
		else
			return count;
	}
};

// Binary search with recursion (recommended)
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN)
		{
			if (divisor == -1)
				return INT_MAX;
			if (divisor == 1)
				return INT_MIN;
		}

		long absDividend = abs((long)dividend), absDivisor = abs((long)divisor);
		long result = helper(absDividend, absDivisor);

		if (result > INT_MAX)
			return INT_MAX;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor >0))
			return -result;
		else
			return result;
	}
	long helper(long absDividend, long absDivisor)
	{
		if (absDividend < absDivisor)
			return 0;
		long sum = absDivisor;
		long result = 1;
		while (absDividend > sum + sum)
		{
			sum += sum;
			result += result;
		}
		return result + helper(absDividend-sum, absDivisor);
	}

};

int main()
{
	int m = -2147483648, n = 3;
	Solution sol;

	int res = sol.divide(m, n);

	cout << res << endl;
}