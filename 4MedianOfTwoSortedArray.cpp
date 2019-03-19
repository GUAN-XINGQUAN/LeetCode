#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int firstMed = (nums1.size() + nums2.size() + 1) / 2;
		int secondMed = (nums1.size() + nums2.size() + 2) / 2;
		double res = (findKthElement(nums1, 0, nums2, 0, firstMed) + findKthElement(nums1, 0, nums2, 0, secondMed)) / 2.0;
		return res;
	}
	// Helper function
	int findKthElement(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k)
	{
		if (start1 >= static_cast<int>(nums1.size()))
			return nums2[start2 + k - 1];
		if (start2 >= static_cast<int>(nums2.size()))
			return nums1[start1 + k - 1];
		if (k == 1)
			return (min(nums1[start1], nums2[start2]));
		int medianValue1, medianValue2;
		if (start1 + k / 2 - 1 < static_cast<int>(nums1.size()))
			medianValue1 = nums1[start1 + k / 2 - 1];
		else
			medianValue1 = INT_MAX;
		if (start2 + k / 2 - 1 < static_cast<int>(nums2.size()))
			medianValue2 = nums2[start2 + k / 2 - 1];
		else
			medianValue2 = INT_MAX;
		if (medianValue1 < medianValue2)
			return findKthElement(nums1, start1 + k / 2, nums2, start2, k-k / 2);
		else
			return findKthElement(nums1, start1, nums2, start2 + k / 2, k-k / 2);
	}
};

int main()
{
	Solution sol;
	int arr1[] = { 1, 3 };
	int arr2[] = { 2 };
	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i != 2; i++)
		vec1.push_back(arr1[i]);
	for (int i = 0; i != 1; i++)
		vec2.push_back(arr2[i]);
	double med = sol.findMedianSortedArrays(vec1, vec2);
	// int med = sol.findKthElement(vec1, 0, vec2, 0, 3);
	cout << med << endl;
}