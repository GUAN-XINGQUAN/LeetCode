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

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = findUpperClosestNumberLocation(arr, x);
        int left = right - 1;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            if (isLeftCloser(arr, left, right, x))
            {
                res.push_back(arr[left]);
                left--;
            }
            else
            {
                res.push_back(arr[right]);
                right++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    int findUpperClosestNumberLocation(vector<int> & arr, int x)
    {
        int left = 0, right = arr.size() - 1;
        while (left + 1 < right)
        {
            int middle = left + (right - left) / 2;
            if (arr[middle] < x)
                left = middle;
            else
                right = middle;
        }
        return right;
    }

    bool isLeftCloser(vector<int>& arr, int left, int right, int x)
    {
        if (left < 0)
            return false;
        if (right > arr.size() - 1)
            return true;
        if (x - arr[left] <= arr[right] - x)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<int> arr = { 0, 0, 1, 2, 3, 3, 4, 7, 7, 8 };
    int k = 4, x = 1;

    Solution sol;
    vector<int> res = sol.findClosestElements(arr, k, x);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\t';
}