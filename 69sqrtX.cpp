#include <iostream>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)
			return x;
		int left = 0, right = x;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (mid <= x / mid)
				left = mid + 1;
			else
				right = mid;
		}
		return left-1;
	}
};

int main()
{
	Solution sol;
	int x = 16;
	int result = sol.mySqrt(x);
	cout << "The result is: " << result << endl;
}