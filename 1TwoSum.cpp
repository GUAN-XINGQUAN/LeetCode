#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity: O(N)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		vector<int> res;
		unsigned i = 0;
		while (i < nums.size())
		{
			unordered_map<int, int>::iterator it = mp.find(target - nums[i]);
			if (it != mp.end())
			{
				res.push_back(it->second);
				res.push_back(i);
				break;
			}
			mp[nums[i]] = i;
			i++;
		}
		return res;
	}
};


int main()
{
	Solution sol;
	int arr[] = { 2, 7, 11, 15 };
	vector<int> nums;
	for (int i = 0; i != 4; i++)
		nums.push_back(arr[i]);
	int target = 9;

	vector<int> res = sol.twoSum(nums, target);
	vector<int>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << endl;
		it++;
	}
}