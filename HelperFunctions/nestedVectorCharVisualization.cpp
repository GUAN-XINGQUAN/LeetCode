#include <iostream>
#include <vector>
#include "NestedVectorCharVisualization.h"

using namespace std;

void nestedVectorCharVisualization(vector<vector<char>> vec)
{
	if (vec.size() == 0)
		cout << "Empty vector!\n";
	vector<vector<char>>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		vector<char>::iterator it2 = it1->begin();
		while (it2 != it1->end())
		{
			cout << *it2 << "\t";
			it2++;
		}
		cout << endl;
		it1++;
	}
};