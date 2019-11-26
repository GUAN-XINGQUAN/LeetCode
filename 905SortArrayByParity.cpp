#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& A)
	{
		if (A.empty())
			return A;
		int left = 0, right = A.size() - 1;
		while (left < right)
		{
			if (A[left] % 2 == 0)
				left++;
			if (A[left] % 2 != 0)
			{
				swap(A[left], A[right]);
				right--;
			}			
		}
		return A;
	}
};


// Test
int main()
{
	vector<int> vec = { 3, 1, 2, 4 };
	Solution sol;
	vector<int> result = sol.sortArrayByParity(vec);
	// Test
	for (unsigned i = 0; i < vec.size(); i++)
	{
		cout << result[i] << '\t';
	}
}