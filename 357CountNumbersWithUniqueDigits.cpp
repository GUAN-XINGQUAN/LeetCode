#include<iostream>

using namespace std;

// Method 1: use the mathematical knowledge:
// One digit number: there are 10. (0, 1, 2, 3, 4, 5, ...9)
// Two digit number: there are 91. (exclude 11, 22, 33 ... 99)
// The generalized formula: f(k) = 9 * 9 * 8 * ... * (9-k+2) where k is the number of digit
//class Solution {
//public:
//	int countNumbersWithUniqueDigits(int n) {
//		int result = 0;
//		if (n == 0)
//			return 1;
//		for (int i = 1; i <= n; i++)
//			result += count(i);
//		return result;
//
//	}
//	int count(int k) {
//		int res = 1;
//		if (k == 0)
//			return 1;
//		if (k == 1)
//			return 10;
//		else
//		{
//			
//			for (int i = 0; i < k-1; i++)
//				res = res * (9 - i);
//			return 9 * res;
//		}
//	}
//};

// Use backtracking approach
class Solution
{
public:
	int countNumbersWithUniqueDigits(int n)
	{

	}
};

int main()
{
	int n = 3;
	Solution sol;
	int res = sol.countNumbersWithUniqueDigits(n);

	cout << "The result is: " << res << endl;
}