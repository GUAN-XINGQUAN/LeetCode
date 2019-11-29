#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

// Method 1: use STL: set
//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		set<int> st1;
//		set<int> st2;
//		for (unsigned i = 0; i < nums1.size(); i++)
//		{
//			if (st1.count(nums1[i]) == 0)
//				st1.insert(nums1[i]);
//		}
//		for (unsigned i = 0; i < nums2.size(); i++)
//		{
//			if (st1.count(nums2[i]) != 0)
//				st2.insert(nums2[i]);
//		}
//		vector<int> res(st2.begin(), st2.end());
//		return res;
//	}
//};


// Method 2: sort two arrays and find intersection
class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		unsigned i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] == nums2[j])
			{
				if (result.empty())
					result.push_back(nums1[i]);
				else if (result.back() != nums1[i])
					result.push_back(nums1[i]);
				i++, j++;
			}
			else if (nums1[i] < nums2[j])
				i++;
			else
				j++;
		}
		return result;
	}
};


int main()
{
	vector<int> nums1 = { 1, 2, 2, 1 };
	vector<int> nums2 = { 2, 2 };
	Solution sol;
	vector<int> res = sol.intersection(nums1, nums2);
	vector<int>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << '\t';
		it++;
	}
}