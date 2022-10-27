#include<iostream>
#include<vector>

using namespace std;


// Method 1: copy a new array
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> numsCopy = nums;
		for (int i = 0; i < nums.size(); i++)
		{
			nums[(i + k) % n] = numsCopy[i];
		}
	}
};


int main()
{
	vector<int> nums = { 0, 1, 2, 3, 4 };
	int k0 = 0, k1 = 1, k2 = 2, k3 = 3, k5 = 5;
	Solution sol;

	sol.rotate(nums, k0);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << '\t';
	cout << endl;
	sol.rotate(nums, k1);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << '\t';
	cout << endl;
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << '\t';
}