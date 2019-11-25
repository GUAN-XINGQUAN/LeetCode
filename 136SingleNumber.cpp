#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// Method 1: use Hash table
//class Solution
//{
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		unordered_map<int, int> mp;
//		for (unsigned i = 0; i < nums.size(); ++i)
//		{
//			unordered_map<int, int>::iterator it = mp.find(nums[i]);
//			if (it == mp.end())
//				mp[nums[i]] = i;
//			else
//				mp.erase(nums[i]);
//		}
//		return mp.begin()->first;
//	}
//};

// Method 2: use set
//class Solution
//{
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		set<int> st;
//		// for (unsigned i = 0; i < nums.size(); i++)
//		for (int num : nums)
//		{
//			if (st.count(num) == 0)
//				st.insert(num);
//			else
//				st.erase(num);
//		}
//		return *(st.begin());
//	}
//};

// Method 3: use linear time complexity without using extra space
class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int result = 0;
		for (int num : nums)
			result ^= num;
		return result;
	}
};

int main()
{
	vector<int> nums = { 2, 2, 1 };
	Solution sol;
	int result = sol.singleNumber(nums);
	cout << "The result is: " << result << endl;
}