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

// Binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left + 1 < right)
        {
            int middle = left + (right - left) / 2;
            if (A[middle] > A[middle + 1])
                right = middle;
            else
                left = middle;
        }
        return A[left] > A[right] ? left : right;
    }
};

int main()
{
    vector<int> vec = { 0, 2, 1, 0 };
    Solution sol;

    int loc = sol.peakIndexInMountainArray(vec);
    cout << loc << endl;
}