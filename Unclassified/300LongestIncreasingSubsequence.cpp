#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Method 1: time complexity O(N^2)
//class Solution
//{
//public:
//	int lengthOfLIS(vector<int> nums)
//	{
//		vector<int> LIS(nums.size(), 1);
//		int length = 0;
//		for (unsigned i = 0; i < nums.size(); i++)
//		{
//			for (unsigned j = 0; j < i; j++)
//			{
//				if (nums[j] < nums[i])
//				{
//					LIS[i] = max(LIS[i], LIS[j] + 1);
//				}
//			}
//			length = max(length, LIS[i]);
//		}
//		return length;
//	}
//};

// Method 2: use BST to achieve O(N log N)
class Solution
{
public:
	int lengthOfLIS(vector<int> nums)
	{
		vector<int> LIS;
		for (int i = 0; i < nums.size(); i++)
		{
			int left = 0, right = LIS.size();
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (LIS[mid] < nums[i])
					left = mid + 1;
				else
					right = mid;
			}
			if (right >= LIS.size())
				LIS.push_back(nums[i]);
			else
				LIS[right] = nums[i];
		}
		return LIS.size();
	}
};



int main()
{
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	Solution sol;
	int length = sol.lengthOfLIS(nums);
	cout << "The result is: " << length << endl;
}