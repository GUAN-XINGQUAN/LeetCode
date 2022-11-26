/*


*/

// classical binary search scenario
// time O(log n)
// space O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (!isBadVersion(mid))
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};

