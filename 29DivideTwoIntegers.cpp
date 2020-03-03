#include<iostream>
#include<cmath>
using namespace std;

class Solution {
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

int main()
{
	int m = 8, n = 1;
	Solution sol;

	int res = sol.divide(m, n);

	cout << res << endl;
}