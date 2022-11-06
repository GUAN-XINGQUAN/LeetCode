/*

search window: [left, right]
termination condition: left <= right --> left = right + 1
once terminate: right^2 < x < left^2 --> return right^2

*/

// approach 1:
// time: O(sqrt root of n)
// space: O(1)
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int i = 1;
        while (i <= x / i)
        {
            if (i == x / i)
                return i;
            i++;
        }
        return i-1;
    }
};



// approach 2:
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int left = 2, right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid == x / mid)
                return mid;
            else if (mid < x /mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};