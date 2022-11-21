/*

*/


// brute force solution
// time O(c) = O(sqrt c) * O(sqrt c)
// space O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        // use long type to avoid overflow
        for (long i = 0; i * i < c; i++)  // O(sqrt c)
        {
            for (long j = 0; j * j < c; j++)  // O(sqrt c)
            {
                if (i * i + j * j == c)
                    return true;
            }
        }
        return false;
    }
};

// linear scan + binary search
// time O(sqrt c * log n)
// space O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; i++)
        {
            if (isValidSquare(c - i * i))
                return true;
        }
        return false;
    }
    
    bool isValidSquare(long target)
    {
        long left = 0, right = target;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            if (mid * mid == target)
                return true;
            else if (mid * mid < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

