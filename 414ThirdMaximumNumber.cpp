#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
		for (int num : nums)
		{
			if (num > first)
			{
				third = second;
				second = first;
				first = num;
			}
			else if (num > second && num < first)
			{
				third = second;
				second = num;
			}
			else if (num < second && num > third)
				third = num;
		}
		if (third == LONG_MIN)
			return first;
		else
			return third;
	}
};


int main()
{
	vector<int> vec1 = { 1, 2, 3, 4 };
	vector<int> vec2 = { 2, 2, 2 };
	vector<int> vec3 = {10};
	vector<int> vec4 = { 1,2 };
	Solution sol;

	assert(sol.thirdMax(vec1) == 2);
	assert(sol.thirdMax(vec2) == 2);
	assert(sol.thirdMax(vec3) == 10);
	assert(sol.thirdMax(vec4) == 2);

	cout << "All test cases passed!\n";

}