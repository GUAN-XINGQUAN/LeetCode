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

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        if (letters[left] > target)
            return letters[left];
        else if (letters[right] > target)
            return letters[right];
        else
            return letters[0];
    }
};


int main()
{
    Solution sol;

}