#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1)
			return s;
		string res = "";
		// Find the relationship between the index of the character in the original string and new string
		// The index in new string is row + 2*numRows - 2
		// If not first or last line, the index needs to add one more term: index + 2numRows - 2 - 2 * row;
		for (int row = 0; row < numRows; row++)
		{
			for (int index = row; index < static_cast<int>(s.size()); index += 2 * numRows - 2)
			{
				res += s[index];
				if (row != 0 && row != numRows - 1 && index+2*numRows-2-2*row <static_cast<int>(s.size()))
					res += s[index + 2 * numRows - 2 - 2 * row];
			}
		}
		return res;
	}
};

int main()
{
	string s = "0123456789ABCDEFGHIJ";
	Solution sol;
	string res = "";
	res = sol.convert(s, 4);
	cout << res << endl;
}