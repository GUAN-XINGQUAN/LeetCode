#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1, count = 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return isValid(s, left + 1, right) || isValid(s, left, right - 1);
            left++;
            right--;
        }
        return true;
    }
    bool isValid(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};


int main()
{
    Solution sol;

}