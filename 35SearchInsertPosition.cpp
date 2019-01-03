#include <iostream>
#include <vector>
using namespace std;

// Method 1: Brute force, i.e. loop over each element
//class Solution
//{
//public:
//	int searchInsert(vector<int>& nums, int target)
//	{
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] >= target)
//				return i;
//		}
//		return nums.size();
//	}
//};

// Method 2: Binary search
class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		// Last element is still smaller than the target
		if (nums.back() < target)
			return nums.size();
		// Use binary search
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return right;
	}
};



int main()
{
	vector<int> vec = { 1, 3, 5, 6 };
	int tar = 4;
	Solution sol;
	cout << sol.searchInsert(vec, tar);
}