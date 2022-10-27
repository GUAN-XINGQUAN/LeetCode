#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> rowFlag(9, vector<bool>(9));
		vector<vector<bool>> colFlag(9, vector<bool>(9));
		vector<vector<bool>> cellFlag(9, vector<bool>(9));
		for (int i = 0; i < static_cast<int>(board.size()); i++)
		{
			for (int j = 0; j < static_cast<int>(board[0].size()); j++)
			{
				if (isdigit(board[i][j]))
				{
					int num = board[i][j] - '0' - 1;
					if (rowFlag[i][num] || colFlag[num][j] || cellFlag[3 * (i / 3) + j / 3][num])
						return false;
					rowFlag[i][num] = true;
					colFlag[num][j] = true;
					cellFlag[3 * (i / 3) + j / 3][num] = true;
				}
			}
		}
		return true;
	}
};


int main()
{
	vector<vector<char>> board = {
			{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	Solution sol;

	if (sol.isValidSudoku(board))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}