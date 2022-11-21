/*


*/

// brute force solution
// time O(sqrt n)
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0, s = n;
        while (s >= i+1)
        {
            s = s - (i+1);
            i++;
            
        }
        return i;
    }
};


// binary search
// time O(log n)
// space O(1)
// (1 + 2 + ... + k) * k / 2 <= n
// find the maximum k
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            if ((1+mid) * mid / 2 == n)
                return mid;
            else if ((1+mid) * mid / 2 > n)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};