#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		int last = prices.size() - 1;
		for (int i = 0; i < last; i++)
		{
			if (prices[i + 1] > prices[i])
				result += prices[i + 1] - prices[i];
		}
		return result;
	}
};

int main()
{
	Solution sol;
	int arr[] = { 7,1,5,3,6,4 };
	vector<int> vec;
	for (int i = 0; i != 6; i++)
		vec.push_back(arr[i]);
	cout << "max profit is " << sol.maxProfit(vec);
}