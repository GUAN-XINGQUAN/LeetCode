#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


// Use STL set, which aovids the repeated element by default.
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		set<vector<int>> result;  // A vector which includes vector as each element
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++)
		{
			for (int j = i + 1; j < n - 2; j++)
			{
				// If jth element is repeated with previous one => not necessary to find the other two elements
				if (j > i + 1 && nums[j] == nums[j - 1])  
					continue;
				int left = j+1, right = n - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target)
					{
						vector<int> temp = { nums[i], nums[j], nums[left], nums[right] };
						result.insert(temp);
						left++;
						right--;
					}
					else if (sum < target)
						left++;
					else
						right--;
				}
			}
		}
		return vector<vector<int>>{result.begin(), result.end()};
	}
};

int main()
{
	Solution sol;
	vector<int> nums = { -3,-2,-1,0,0,1,2,3 };
	vector<vector<int>> result = sol.fourSum(nums, 0);
	// Display the results
	vector<vector<int>>::iterator myIt = result.begin();
	while (myIt != result.end())
	{
		vector<int>::iterator innerIt = (*myIt).begin();
		while (innerIt != (*myIt).end())
		{
			cout << *innerIt << ' ';
			innerIt++;
		}
		cout << endl;
		myIt++;
	}
}