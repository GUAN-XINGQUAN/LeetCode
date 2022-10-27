#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (unsigned i = 0; i < nums.size(); i++)
		{
			int index = abs(nums[i]) - 1;
			if (nums[index] > 0)
				nums[index] = nums[index] * (-1);
		}
		for (unsigned i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				result.push_back(i + 1);
		}
		return result;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 2, 4 };
	Solution sol;
	vector<int> res = sol.findDisappearedNumbers(nums);

	// Display the result
	vector<int>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << '\t';
		it++;
	}
}