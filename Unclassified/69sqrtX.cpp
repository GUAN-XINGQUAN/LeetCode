#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorCharVisualization.h"

using namespace std;

// Binary search
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = x;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (mid < x / mid)
                left = mid;
            else
                right = mid;
        }
        // cout << left << '\t' << right << endl;
        return (right <= x / right) ? right : left;
    }
};

int main()
{
    double x = 10;
   
    Solution sol;

    int res = sol.mySqrt(x);

    cout << res << endl;
   
    
}
