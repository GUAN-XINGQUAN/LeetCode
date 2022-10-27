#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0)
        {
            int p = m >= 0 ? a[m] - '0' : 0;
            int q = n >= 0 ? b[n] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
            m--;
            n--;
        }
        return carry == 1 ? "1" + res : res;
    }
};


int main()
{
    Solution sol;

    string a = "11", b = "1";
    string res = sol.addBinary(a, b);

    cout << res << endl;
}