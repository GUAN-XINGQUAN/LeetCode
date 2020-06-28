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

// Linear scan O(N) (Not recommended)
class Solution1 {
public:
    int hIndex(vector<int>& citations) {
        int count = 1;
        for (int i = citations.size() - 1; i >= 0; i--)
        {
            if (citations[i] < count)
                break;
            count++;
        }
        return count - 1;
    }
};


// Follow up: binary search ==> O(log N)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int totalPaper = citations.size();
        int left = 0, right = citations.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= totalPaper - mid)
                right = mid;
            else
                left = mid;
        }
        if (citations.empty())
            return 0;
        else if (citations.size() == 1)
            return citations[0] >= 1 ? 1 : 0;
        else if (citations[left] >= totalPaper - left)
            return totalPaper - left;
        else if (citations[right] >= totalPaper - right)
            return totalPaper - right;
        else
            return 0;
    }
};


int main()
{
    vector<int> citations = { 0,0 };
    Solution sol;

    int res = sol.hIndex(citations);

    cout << res << endl;
}