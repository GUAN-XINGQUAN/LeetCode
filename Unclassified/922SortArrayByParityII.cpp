#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		if (A.empty())
			return A;
		unsigned even = 0, odd = 1;
		while (even < A.size() - 1 && odd <= A.size() - 1)
		{
			if (A[even] % 2 == 0)
				even += 2;
			else if (A[odd] % 2 == 1)
				odd += 2;
			else
			{
				swap(A[even], A[odd]);
				even += 2;
				odd += 2;
			}
		}
		return A;
	}
};

int main()
{
	vector<int> A = { 3,0,4,0,2,1,3,1,3,4 };
	Solution sol;
	vector<int> result = sol.sortArrayByParityII(A);
	vector<int>::iterator it = result.begin();
	while (it != result.end())
	{
		cout << *it << '\t';
		it++;
	}
	cout << endl;
}