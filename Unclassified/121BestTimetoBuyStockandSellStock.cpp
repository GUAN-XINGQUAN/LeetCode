#include <limits>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int buy = INT_MAX, result = 0;
		for (int i = 0; i != prices.size(); i++)
		{
			buy = min(buy, prices[i]);
			result = max(result, prices[i]-buy);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	int arr[] = { 7, 2, 5, 3, 10, 4 };
	vector<int> vec;
	for (int i = 0; i != 6; i++)
		vec.push_back(arr[i]);
	for (vector<int>::iterator it=vec.begin(); it != vec.end(); it++)
		cout << *it << endl;
	cout << "Final result is: " << sol.maxProfit(vec);
}