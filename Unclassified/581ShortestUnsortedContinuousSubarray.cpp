#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Method 1:
//class Solution {
//public:
//	int findUnsortedSubarray(vector<int>& nums) {
//		int start = -1, result = 0;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (nums[i] < nums[i - 1])
//			{
//				int j = i;
//				while (j > 0 && nums[j] < nums[j - 1])
//				{
//					swap(nums[j], nums[j - 1]);
//					j--;
//				}
//				if (start == -1 || start > j)
//					start = j;
//				result = i - start + 1;
//			}
//		}
//		return result;
//	}
//};

// Method 2:
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> numsCopy(nums.begin(), nums.end());
		sort(numsCopy.begin(), numsCopy.end());
		int start = 0, end = numsCopy.size() - 1, result;
		while (start < numsCopy.size() && numsCopy[start] == nums[start])
			start++;
		while (end >= start && numsCopy[end] == nums[end])
			end--;
		result = end - start + 1;
		return result;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 5, 4, 2 };
	Solution sol;

	int result = sol.findUnsortedSubarray(nums);

	// Display the result
	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		cout << *it << '\t';
		it++;
	}
	cout << "Shortest length is: " << result << endl;
}