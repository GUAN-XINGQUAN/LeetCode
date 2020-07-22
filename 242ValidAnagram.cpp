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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> char2Count;
        for (int i = 0; i < s.size(); i++)
            ++char2Count[s[i]];

        for (int j = 0; j < t.size(); j++)
        {
            if (char2Count.count(t[j]) != 0)
                --char2Count[t[j]];
        }

        int count = 0;
        unordered_map<char, int>::iterator it = char2Count.begin();
        while (it != char2Count.end())
        {
            if (it->second != 0)
                count++;
            it++;
        }

        if (count == 0)
            return true;
        else
            return false;
    }
};


int main()
{
    string s = "anagram", t = "nagaram";
    Solution sol;

    if (sol.isAnagram(s, t))
        cout << "YES\n";
    else
        cout << "NO\n";
    
}