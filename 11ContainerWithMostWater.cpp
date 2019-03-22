#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0, left = 0, right = height.size() - 1;
		while (left < right)
		{
			int h = height[left] > height[right] ? height[right] : height[left];
			int area = h * (right - left);
			if (area > res)
				res = area;
			if (height[left] < height[right])
				++left;
			else
				--right;
		}
		return res;
	}
};

int main()
{
	int arr[] = { 1,8,6,2,5,4,8,3,7 };
	vector<int> vec;
	for (int i = 0; i != 9; i++)
		vec.push_back(arr[i]);
	Solution sol;
	int res = sol.maxArea(vec);
	cout << res << endl;
}