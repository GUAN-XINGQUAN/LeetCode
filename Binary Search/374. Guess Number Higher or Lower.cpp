/*

The core is LeetCode 704. The wrapper is a function guess(int n) which reveals the relationship between your input and the actual number.

searching window [left, right] with both ends inclusive

termination condition: left <= right, which means the searching window looks like [right+1, right] with zero element

why left = mid + 1 and right = mid - 1:

we already searched the middle element and the next iteration should remove this middle element

*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int guessResult = guess(mid);
            if (guessResult == 0)
                return mid;
            else if (guessResult == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};