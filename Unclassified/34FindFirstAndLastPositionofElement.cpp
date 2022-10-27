#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		int index = searchTarget(nums, target, 0, nums.size() - 1);
		vector<int> res(2, -1);
		if (index == -1)
			return res;
		int left = index, right = index;
		while (left >= 0 && nums[left] == target)
			left--;
		while (right <= nums.size() - 1 && nums[right] == target)
			right++;
		res[0] = left + 1;
		res[1] = right - 1;
		return res;
	}
	int searchTarget(vector<int>& nums, int target, int left, int right)
	{
		if (right < left)
			return -1;
		int mid = left + (right-left) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[mid] > target)
			return searchTarget(nums, target, left, mid - 1);
		else
			return searchTarget(nums, target, mid + 1, right);
	}
};

int main()
{
	vector<int> vec = { 5,7,7,8,8,10 };
	int target = 8;
	Solution sol;
	vector<int> res = sol.searchRange(vec, target);
	cout << res[0] << ' ' << res[1] << endl;
	//int res = sol.searchTarget(vec, target, 0, 0);
	//cout << res << endl;
}