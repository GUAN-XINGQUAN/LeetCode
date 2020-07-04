#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int res = 0, left = -1, right = 0;
        while (right < s.size())
        {
            if (charMap.count(s[right]) > 0 && charMap[s[right]] > left)
                left = charMap[s[right]];
            charMap[s[right]] = right;
            res = max(res, right - left);
            right++;
        }
        return res;
    }
};

int main()
{
    string str = "aaa";
    
    Solution sol;

    int res = sol.lengthOfLongestSubstring(str);

    cout << res << endl;

}