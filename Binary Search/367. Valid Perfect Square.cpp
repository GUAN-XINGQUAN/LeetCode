/*

search window: [left, right]
termination condition: left <= right
if mid * mid == num --> return true
once terminates: left = right + 1 --> return false

be cautious with overflow of the integer, so use long.

*/

// time O(sqrt n)
// space O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (i <= num / i)
        {
            if (i * i == num)
                return true;
            i++;
        }
        return false;
    }
};


// time O (log n)
// space O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 1, right = num;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            if (mid * mid == num)
                return true;
            else if (mid < num / mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};