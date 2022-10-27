#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

// Moore voting
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0, target;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0)
				target = nums[i];
			if (nums[i] == target)
				count++;
			else
				count--;
		}
		return target;
	}
};

int main()
{
	Solution sol;
	vector<int> vec1 = { 1, 1, 2, 1 };
	vector<int> vec2 = { 1 };
	vector<int> vec3 = { 2, 2, 3 };
	vector<int> vec4 = { 1, 1, 2, 2, 3, 3, 3 };

	assert(sol.majorityElement(vec1) == 1);
	assert(sol.majorityElement(vec2) == 1);
	assert(sol.majorityElement(vec3) == 2);
	assert(sol.majorityElement(vec4) == 3);

	cout << "All test cases passed!\n";

}