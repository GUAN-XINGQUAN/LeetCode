#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Sort the two arrays and find the intersection
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		unsigned i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] == nums2[j])
			{
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
	vector<int> res = sol.intersect(nums1, nums2);

	// Display the result
	vector<int>::iterator it = res.begin();
	while (it != res.end())
	{
		cout << *it << '\t';
		it++;
	}
}