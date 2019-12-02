#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Method 1: Brute force
//class Solution {
//public:
//	int wiggleMaxLength(vector<int>& nums) {
//		if (nums.size() < 2)
//			return nums.size();
//		return 1 + max(countLength(nums, 0, true), countLength(nums, 0, false));
//	}
//
//	int countLength(vector<int>& nums, int startIndex, bool isUp) {
//		int maxCount = 0;
//		for (int i = startIndex + 1; i < nums.size(); i++)
//		{
//			if (isUp && nums[i] > nums[startIndex])
//				maxCount = max(maxCount, 1+countLength(nums, i, !isUp));
//			else if (!isUp && nums[i] < nums[startIndex])
//				maxCount = max(maxCount, 1+countLength(nums, i, !isUp));
//		}
//		return maxCount;
//	}
//};

// Method 2: Use dynamic programming
//class Solution {
//public:
//	int wiggleMaxLength(vector<int>& nums) {
//		if (nums.empty())
//			return 0;
//		vector<int> positive(nums.size(), 1);
//		vector<int> negative(nums.size(), 1);
//		for (unsigned i = 1; i < nums.size(); i++)
//		{
//			for (unsigned j = 0; j < i; j++)
//			{
//				if (nums[i] > nums[j])
//					positive[i] = max(positive[i], negative[j] + 1);
//				else if (nums[i] < nums[j])
//					negative[i] = max(negative[i], positive[j] + 1);
//			}
//		}
//		return max(positive.back(), negative.back());
//	}
//};

// Method 3: use greedy algorithm
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		int up = 1, down = 1;
		for (unsigned i = 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[i - 1])
				up = down + 1;
			else if (nums[i] < nums[i - 1])
				down = up + 1;
		}
		return max(up, down);
	}
};

int main()
{
	vector<int> vec = { 1, 3, 2 };
	Solution sol;
	int length = sol.wiggleMaxLength(vec);
	
	cout << "The final answer is: " << length << endl;

}