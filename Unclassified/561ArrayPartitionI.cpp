#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

// Greedy algorithm
// Each group should have two numbers with close value
class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int res = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i += 2)
		{
			res += nums[i];
		}
		return res;
	}
};

int main()
{
	vector<int> nums1 = { 1, 4, 3, 2 };
	vector<int> nums2 = { 2, 2, 2, 2 };
	vector<int> nums3 = { 10, 20, 3, 4 };
	vector<int> nums4 = { 1, 2, 3, 4, 5, 6 };

	Solution sol;

	assert(sol.arrayPairSum(nums1) == 4);
	assert(sol.arrayPairSum(nums2) == 4);
	assert(sol.arrayPairSum(nums3) == 13);
	assert(sol.arrayPairSum(nums4) == 9);
	cout << "All test cases passed!\n";
}