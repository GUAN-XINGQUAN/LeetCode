#include<iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num)
{
	if (6 > num)
		return 1;
	else if (6 < num)
		return -1;
	else
		return 0;
}

class Solution {
public:
	int guessNumber(int n) {
		if (guess(n) == 0)
			return n;
		int left = 1, right = n;
		while (left < right)
		{
			int mid = left + (right - left) / 2, res = guess(mid);
			if (res == 0)
				return mid;
			else if (res == 1)
				left = mid + 1;
			else
				right = mid;
		}		
		return left;
	}
};

int main()
{
	int num = 10;
	Solution sol;
	int res = sol.guessNumber(num);

	cout << "The final answer is: " << res << endl;
	
}