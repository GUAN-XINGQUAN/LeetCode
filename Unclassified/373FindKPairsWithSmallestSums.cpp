#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// Method 1: brute force
bool comparator(pair<int, int> p1, pair<int, int>p2)
{
	if (p1.first + p1.second < p2.first + p2.second)
		return true;
	else
		return false;
}

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> result;
		for (int i = 0; i < min(int(nums1.size()), k); i++)
		{
			for (int j = 0; j < min(int(nums2.size()), k); j++)
				result.push_back({ nums1[i], nums2[j] });
		}
		sort(result.begin(), result.end(), comparator);
		vector<vector<int>> finalResult;
		for (int i = 0; i < min(int(result.size()), k); i++)
		{
			finalResult.push_back({ result[i].first, result[i].second });
		}
		return finalResult;
	}
};

int main()
{
	vector<int> nums1 = { 1, 7, 11 };
	vector<int> nums2 = { 2, 4, 6 };
	int k = 3;
	Solution sol;

	vector<vector<int>> res = sol.kSmallestPairs(nums1, nums2, k);
	
	// Display the result
	vector<vector<int>>::iterator it = res.begin();
	while (it != res.end())
	{
		vector<int>::iterator itt = (*it).begin();
		while (itt != (*it).end())
		{
			cout << *itt << '\t';
			itt++;
		}
		cout << endl;
		it++;
	}
}