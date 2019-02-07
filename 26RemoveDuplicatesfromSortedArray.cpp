#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 1)
			return nums.size();
		int i = 0, j = 0;
		while (j != nums.size())
		{
			if (nums[i] == nums[j])
				j++;
			else
			{
				i++;
				nums[i] = nums[j];
				j++;
			}
		}
		return (i+1);
	}
};


int main()
{
	vector<int> nums = { };
	Solution sol;
	int result = sol.removeDuplicates(nums);
	cout << "The size is: " << result << endl;
	cout << "The array is listed below: \n";
	for (int k = 0; k != nums.size(); k++)
		cout << nums[k] << endl;
}