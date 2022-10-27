#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; j < nums.size(); j++)
		{
			if (nums[j] != 0)
			{
				swap(nums[i], nums[j]);
				i++;
			}

		}
	}
};

int main()
{
	Solution sol;
	vector<int> nums = { 1, 2, 3, 4 };
	sol.moveZeroes(nums);
	
	//Display the vector
	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		cout << *it << '\t';
		it++;
	}

}

