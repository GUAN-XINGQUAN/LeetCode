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

// brute force approach
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;
        vector<int> divisors = findPositiveDivisors(num);
        int sum = 0;
        for (int each : divisors)
        {
            sum += each;
            if (sum == num)
                return true;
        }
        return false;
    }
    vector<int> findPositiveDivisors(int num)
    {
        vector<int> res = { 1 };
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
                res.push_back(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
}