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

// time limit exceeds
class Solution1 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> pQ;
        pQ.push(1);

        for (int i = 1; i < n; i++)
        {
            long temp = pQ.top();
            pQ.pop();
            while (!pQ.empty() && pQ.top() == temp)
                pQ.pop();
            for (int each : primes)
                pQ.push(temp * each);
        }
        return pQ.top();
    }
};

// optimized approach
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1);
        vector<int> index(primes.size(), 0);

        while (res.size() < n)
        {
            vector<int> temp;
            int mn = INT_MAX;
            for (int i = 0; i < primes.size(); i++)
            {
                temp.push_back(res[index[i]] * primes[i]);
            }

            for (int i = 0; i < primes.size(); i++)
                mn = min(mn, temp[i]);

            for (int i = 0; i < primes.size(); i++)
            {
                if (temp[i] == mn)
                    ++index[i];
            }

            res.push_back(mn);
        }
        return res.back();;
    }
};

int main()
{
    vector<int> primes = { 2, 7, 13, 19 };
    int n = 12;

    Solution sol;

    int res = sol.nthSuperUglyNumber(n, primes);

    cout << res << endl;
}
