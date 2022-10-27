#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = (0 + (nums.size()+1)) * nums.size() / 2;
		for (unsigned i = 0; i < nums.size(); i++)
		{
			sum -= nums[i];
		}
		return sum;
	}
};

int main()
{
	Solution sol;
	vector<int> vec = { 3, 0, 1 };
	int result = sol.missingNumber(vec);
	cout << "The final answer is: " << result << endl;
}