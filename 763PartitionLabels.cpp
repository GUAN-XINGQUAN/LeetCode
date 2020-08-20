#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> char2Index;
        for (int i = 0; i < S.size(); i++)
            char2Index[S[i]] = i;
        
        int start = 0, last = 0;
        vector<int> res;
        for (int i = 0; i < S.size(); i++)
        {
            last = max(last, char2Index[S[i]]);
            if (i == last)
            {
                res.push_back(last - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    string s = "ababcbacadefegdehijhklij";

    vector<int> res = sol.partitionLabels(s);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}