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

// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    if (version >= 1)
        return true;
    else
        return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while (left + 1 < right)
        {
            int middle = left + (right - left) / 2;
            if (isBadVersion(middle))
                right = middle;
            else
                left = middle;
        }
        if (isBadVersion(left))
            return left;
        else if (isBadVersion(right))
            return right;
        else
            return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.firstBadVersion(1);
}