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

// Brute force (time limit exceed)
class Solution1 {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int x = 2; x < n; x++)
        {
            if (isPrime(x))
                res++;
        }
        return res;
    }

    bool isPrime(int x)
    {
        // 1 is not a prime
        if (x == 1)
            return false;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
};

// Optimized approach
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }

        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
                res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int res = sol.countPrimes(35);
    cout << res << endl;
}