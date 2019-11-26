#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		unordered_map<int, int> mp;
		vector<int> result;
		vector<int> redundancy;
		for (unsigned i = 0; i < arr1.size(); i++)
		{
			if (mp.find(arr1[i]) == mp.end())
				mp[arr1[i]] = 1;
			else
				mp[arr1[i]] += 1;
		}
		for (unsigned i = 0; i < arr2.size(); i++)
		{
			unordered_map<int, int>::iterator it = mp.find(arr2[i]);
			for (int j = 0; j < it->second; j++)
			{
				result.push_back(arr2[i]);
			}
			mp[arr2[i]] -= it->second;
		}
		unordered_map<int, int>::iterator it = mp.begin();
		while (it != mp.end())
		{
			for (int i = 0; i < it->second; i++)
				redundancy.push_back(it->first);
			it++;
		}
		sort(redundancy.begin(), redundancy.end());
		for (int each : redundancy)
			result.push_back(each);
		return result;
	}
};

int main()
{
	vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
	vector<int> arr2 = { 2,1,4,3,9,6 };
	Solution sol;
	vector<int> result = sol.relativeSortArray(arr1, arr2);
	vector<int>::iterator it = result.begin();
	while (it != result.end())
	{
		cout << *it << '\t';
		it++;
	}
}