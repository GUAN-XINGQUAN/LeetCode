#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorIntVisualization.h"

using namespace std;

// Brute force O(N+M) where N is the number of characters in t and M is the number of 
// characters in s.
// Use two index.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0)
            return true;
        int sIndex = 0, tIndex = 0;
        while (tIndex < t.size() && sIndex < s.size())
        {
            if (t[tIndex] == s[sIndex])
                sIndex++;
            tIndex++;
        }

        if (sIndex == s.size())
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "acb";
    string t = "ahbgdc";

    Solution sol;

    if (sol.isSubsequence(s, t))
        cout << "YES\n";
    else
        cout << "No\n";
}