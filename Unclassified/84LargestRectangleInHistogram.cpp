#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Method 1:
//class Solution
//{
//public:
//	int largestRectangleArea(vector<int>& heights)
//	{
//		int returnValue = 0;
//		for (int i = 0; i != heights.size(); i++)
//		{
//			if (i < heights.size() - 1 && heights[i] < heights[i + 1])
//				continue;
//			int currentH = heights[i];
//			for (int j = i; j >= 0; j--)
//			{
//				currentH = min(currentH, heights[j]);
//				int area = currentH * (i - j + 1);
//				returnValue = max(returnValue, area);
//			}
//		}
//		return returnValue;
//	}
//};

// Method 2:
//class Solution
//{
//public:
//	int largestRectangleArea(vector<int>& heights)
//	{
//		int returnValue = 0;  // Declare a variable to store final area
//		stack<int> st;  // Declare a stack variable to store ascending order index
//		heights.push_back(0);  // Add a zero to terminate the montonic increasing order of heights
//		for (int i = 0; i < heights.size(); i++)
//		{
//			if (st.empty() || heights[st.top()] < heights[i])
//				st.push(i);
//			else
//			{
//				int current = st.top();
//				st.pop();
//				returnValue = max(returnValue, heights[current] * (st.empty() ? i : (i - st.top() - 1)));
//				i--;
//			}
//		}
//		return returnValue;
//	}	
//};

// Method 3: further simplify method 2
class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		int returnValue = 0;
		stack<int> st;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++)
		{
			while (!st.empty() && heights[st.top()] >= heights[i])
			{
				int current = st.top();
				st.pop();
				returnValue = max(returnValue, heights[current] * (st.empty() ? i : (i - st.top() - 1)));
			}
			st.push(i);
		}
		return returnValue;
	}
};


int main()
{
	vector<int> vec = { 2, 1, 5, 6, 2, 3 };
	Solution sol;
	cout << sol.largestRectangleArea(vec) << endl;
}