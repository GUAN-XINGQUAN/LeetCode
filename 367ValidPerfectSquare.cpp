#include<iostream>

using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		long left = 0, right = num;
		while (left < right)
		{
			long mid = (left + right) / 2;
			if (mid * mid < num)
				left = mid + 1;
			else
				right = mid;
		}
		if (right * right == num)
			return true;
		return false;
	}
};


int main()
{
	int num = 3;
	Solution sol;
	if (sol.isPerfectSquare(num))
		cout << "Perfect square\n";
	else
		cout << "No!!!\n";
}