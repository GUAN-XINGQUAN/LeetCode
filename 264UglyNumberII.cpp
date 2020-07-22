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

// brute force
class Solution1 {
public:
    int nthUglyNumber(int n) {
        int count = 0, ug = 1;
        while (count < n)
        {
            if (isUglyNumber(ug))
                count++;
            ug++;
        }
        return ug-1;
    }
    bool isUglyNumber(int x)
    {
        if (x == 0)
            return false;
        while (x % 2 == 0)
            x = x / 2;
        while (x % 3 == 0)
            x = x / 3;
        while (x % 5 == 0)
            x = x / 5;

        if (x == 1)
            return true;
        else
            return false;
    }
};


// optimized approach
class Solution2 {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n)
        {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int minValue = min(m2, min(m3, m5));
            if (minValue == m2)
                i2++;
            if (minValue == m3)
                i3++;
            if (minValue == m5)
                i5++;
            res.push_back(minValue);
        }
        return res.back();
    }
};


// optimized approach: use heap
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pQ;
        pQ.push(1);

        for (int i = 0; i < n-1; i++)
        {
            int temp = pQ.top();
            pQ.pop();
            while (!pQ.empty() && pQ.top() == temp)
                pQ.pop();
            pQ.push(temp * 2);
            pQ.push(temp * 3);
            pQ.push(temp * 5);
        }
        return pQ.top();
    }
};


int main()
{
    int n = 10;

    Solution sol;

    int res = sol.nthUglyNumber(n);

    cout << res << endl;
}
