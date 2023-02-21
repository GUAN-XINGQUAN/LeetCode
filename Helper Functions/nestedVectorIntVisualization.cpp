#include <iostream>
#include <vector>
#include "NestedVectorIntVisualization.h"

using namespace std;

void nestedVectorIntVisualization(vector<vector<int>> vec)
{
	if (vec.size() == 0)
		cout << "Empty vector!\n";
	vector<vector<int>>::iterator it1 = vec.begin();
	while (it1 != vec.end())
	{
		vector<int>::iterator it2 = it1->begin();
		while (it2 != it1->end())
		{
			cout << *it2 << "\t";
			it2++;
		}
		cout << endl;
		it1++;
	}
};