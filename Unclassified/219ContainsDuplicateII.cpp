#include<iostream>
#include<vector>
#include<unordered_map>
#include<cassert>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++)
		{
			if (mp.count(nums[i]) != 0 && i - mp[nums[i]] <= k)
				return true;
			else
				mp[nums[i]] = i;
		}
		return false;
	}
};

int main()
{
	vector<int> nums1 = { 1, 2, 3, 1 };
	vector<int> nums2 = { 1, 0, 1, 1 };
	vector<int> nums3 = { 1, 2, 3, 1, 2, 3 };
	int k1 = 3, k2 = 1, k3 = 2;
	Solution sol;

	assert(sol.containsNearbyDuplicate(nums1, k1) == true);
	assert(sol.containsNearbyDuplicate(nums2, k2) == true);
	assert(sol.containsNearbyDuplicate(nums3, k3) == false);

	cout << "All test cases passed!\n";
}