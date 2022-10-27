#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (flowerbed.front() == 0)
			flowerbed.insert(flowerbed.begin(), 0);
		if (flowerbed.back() == 0)
			flowerbed.push_back(0);
		int countConsecutiveZero = 0, sum = 0;
		for (int i = 1; i <= flowerbed.size(); i++)
		{
			
			if (i < flowerbed.size() && flowerbed[i] == flowerbed[i - 1])
				countConsecutiveZero++;
			else
			{
				sum += countConsecutiveZero / 2;
				countConsecutiveZero = 0;
			}
		}
		return sum >= n;
	}
};


int main()
{
	vector<int> flowerbed = { 1,0,0,0,1,0,0 };
	Solution sol;
	if (sol.canPlaceFlowers(flowerbed, 2))
		cout << "Yes.\n";
	else
		cout << "No.\n";
}