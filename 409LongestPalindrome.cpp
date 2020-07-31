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

// Even number of letters
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> char2Freq;
        for (char ch : s)
            ++char2Freq[ch];

        unordered_map<char, int>::iterator it = char2Freq.begin();
        
        bool isMid = false;
        int count = 0;
        while (it != char2Freq.end())
        {
            count += it->second;
            if (it->second % 2 == 1)
            {
                isMid = true;
                count--;
            }
            it++;
        }

        if (isMid)
            return count + 1;
        else
            return count;
    }
};


int main()
{
    string s = "abc";
    Solution sol;
    int res = sol.longestPalindrome(s);

    cout << res << endl;
}