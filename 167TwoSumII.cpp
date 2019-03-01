#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n^2)
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& numbers, int target) {
//		vector<int> ans;
//		for (int i = 0; i != numbers.size()-1; i++)
//			for (int j = i + 1; j != numbers.size(); j++)
//			{
//				if (numbers[i] + numbers[j] == target)
//				{
//					ans.push_back(i+1);
//					ans.push_back(j+1);
//					return ans;
//				}
//			}
//		return ans;
//	}
//};

// Time complexity: O(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1;
		vector<int> ans;
		while (left < right)
		{
			if (numbers[left] + numbers[right] == target)
			{
				ans.push_back(left+1);
				ans.push_back(right+1);
				break;
			}
			else if (numbers[left] + numbers[right] < target)
				left++;
			else
				right--;
		}
		return ans;
	}
};


int main()
{
	int arr[] = { 2, 7, 11, 15 }, target = 9;
	vector<int> numbers;
	for (int i = 0; i != 4; i++)
		numbers.push_back(arr[i]);
	Solution sol;
	vector<int> answer = sol.twoSum(numbers, target);
	vector<int>::iterator it = answer.begin();
	while (it != answer.end())
	{
		cout << *it << endl;
		it++;
	}
}