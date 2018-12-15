#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());  // Re-list in ascending order
		if (nums.empty() || nums.front() > 0 || nums.back() < 0)
			return {};
		vector<vector<int>> returnValue;
		for (int i = 0; i < nums.size()-2; i++)
		{
			if (nums[i] > 0)
				break;
			if (i >= 1 && nums[i] == nums[i - 1])
				continue;
			int targetSum = 0 - nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				if (nums[left] + nums[right] == targetSum)
				{
					returnValue.push_back({ nums[i], nums[left], nums[right] });
					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
				else if (nums[left] + nums[right] < targetSum)
					left++;
				else
					right--;
			}
		}
		return returnValue;
	}
};

int main()
{
	vector<int> a = {-2, 0, 0, 2, 2};
	Solution sol;
	vector<vector<int>> result = sol.threeSum(a);
	for (int i = 0; i != result.size(); i++)
	{
		for (int j = 0; j != result[0].size(); j++)
			cout << result[i][j] << '\t';
		cout << endl;
	}
}