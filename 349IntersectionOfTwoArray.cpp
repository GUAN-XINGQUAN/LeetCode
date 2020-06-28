#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

// Solution 1: use STL set (take advantage of C++)
class Solution1 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_set<int> num1Set, num2Set;
		for (int i = 0; i < nums1.size(); i++)
		{
			if (num1Set.count(nums1[i]) == 0)
				num1Set.insert(nums1[i]);
		}
		for (int j = 0; j < nums2.size(); j++)
		{
			if (num2Set.count(nums2[j]) == 0)
				num2Set.insert(nums2[j]);
		}
		for (int each : num2Set)
		{
			if (num1Set.count(each) != 0)
				result.push_back(each);
		}
		return result;
	}
};

// Solution 3: use binary search
class Solution2 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result;
		sort(nums1.begin(), nums1.end());
		for (int i = 0; i < nums2.size(); i++)
		{
			if (isInArray(nums1, nums2[i]))
				result.insert(nums2[i]);
		}
		return vector<int> {result.begin(), result.end()};
	}
	bool isInArray(vector<int> nums, int target)
	{
		if (nums.empty())
			return false;
		int left = 0, right = nums.size() - 1;
		while (left + 1 < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid;
			else
				right = mid;
		}
		if (right < left)
			return false;
		else if (nums[left] == target)
			return true;
		else if (nums[right] == target)
			return true;
		else
			return false;
	}
};

// Simplify the binary search codes
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result;
		sort(nums1.begin(), nums1.end());
		for (int i = 0; i < nums2.size(); i++)
		{
			if (isInArray(nums1, nums2[i]))
				result.insert(nums2[i]);
		}
		return vector<int> {result.begin(), result.end()};
	}
	bool isInArray(vector<int> nums, int target)
	{
		int left = 0, right = nums.size();
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return true;
			if (nums[mid] < target)
				left = mid+1;
			else
				right = mid;
		}
		return false;
	}
};

int main()
{
	vector<int> nums1 = { 4,9,5 };
	vector<int> nums2 = { 9,4,9,8,4 };
	Solution sol;
	vector<int> res = sol.intersection(nums1, nums2);
	vector<int>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << '\t';
		it++;
	}
}