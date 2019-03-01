#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <algorithm>
using namespace std;

// Time complexity O(n^2)
//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		for (unsigned i = 0; i != nums.size()-1; i++)
//			for (unsigned j = 0; j != nums.size(); j++)
//			{
//				if (nums[j] == nums[i])
//					return true;
//			}
//		return false;
//	}
//};

// Time complexity O() depends on sort algorithm
//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		if (nums.size() == 0 || nums.size() == 1)
//			return false;
//		sort(nums.begin(), nums.end());
//		for (unsigned i = 1; i != nums.size(); i++)
//			if (nums[i] == nums[i - 1])
//				return true;
//		return false;
//	}
//};


// Time complexity O(n)
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> hashTable;
		for (unsigned i = 0; i != nums.size(); i++)
		{
			std::cout << nums[i];
			if (hashTable.find(nums[i]) != hashTable.end())
				return true;
			// Remeber to store the element into key, not values.
			hashTable[nums[i]] = i;
		}
		return false;
	}
};

int main()
{
	int arr[] = { 1, 2, 3, 3 };
	vector<int> number;
	for (int i = 0; i != 4; i++)
		number.push_back(arr[i]);
	Solution sol;
	assert(sol.containsDuplicate(number));
	//map<int, int> m;
	//m[1];
	//++m[2];
	//++m[3];
	//++m[1000];
	//map<int, int>::iterator it = m.begin();
	//while (it != m.end())
	//{
	//	cout << it->first << "=>" << it->second << endl;
	//	it++;
	//}
}