#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < nums[right])
			{
				if (nums[mid] <= target && nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			else
			{
				if (nums[mid] >= target && nums[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		return -1;
	}
};

int main()
{
	vector<int> vec = { 4,5,6,7,0,1,2 };
	Solution sol;
	int res = sol.search(vec, 4);
	assert(res == 0);
}