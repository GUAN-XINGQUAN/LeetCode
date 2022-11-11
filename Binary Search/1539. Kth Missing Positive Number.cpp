/*
    
*/


// brute force approach
// time O(n)
// space O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // case 1:
        // k < arr.front() --> return k
        if (k < arr.front())
            return k;
        
        k = k - (arr[0] - 1);
        
        // case 2:
        // number of missing numbers nn = arr[i] - arr[i-1] - 1
        // k = k - nn
        // if nn > k
        // retrieve the number between arr[i] and arr[i-1]
        for (int i = 0; i < arr.size()-1; i++)
        {
            int gap = arr[i+1] - arr[i] - 1;
            if (gap >= k)
                return arr[i] + k;
            else
                k -= gap;
        }
        // case 3:
        // finsh the entire array but k > 0
        // count from arr.back() + k
        return arr.back() + k;
    }
};


// the number of missing number before arr[i] is arr[i] - [i] - 1
// binary search
// if arr[mid] - [mid] - 1 < k --> search right half
// else --> search left half
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        // right, left=right+1
        // return arr[right] + k - (arr[right] - right - 1);
        return right + 1 + k;
    }
};