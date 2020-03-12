#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// The replacement must be in-place and use only constant extra memory.
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int j, n = nums.size();
		for (int i = n - 2; i >= 0; i--)
		{
			if (nums[i + 1] > nums[i])
			{
				for (j = n - 1; j > i; j--)
				{
					if (nums[j] > nums[i])
						break;
				}
				swap(nums[i], nums[j]);
				reverse(nums.begin() + i + 1, nums.end());
				return;
			}
		}
		reverse(nums.begin(), nums.end());
		return;
	}
};



int main()
{
	Solution sol;
	vector<int> nums = { 2, 3, 1 };

	sol.nextPermutation(nums);

	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		cout << *it << '\t';
		it++;
	}
}