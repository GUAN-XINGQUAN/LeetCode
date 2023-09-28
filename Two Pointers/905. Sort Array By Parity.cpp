/*
Approach #1:
1. Create a new array which will be used to store the results.
2. Use two pointers: 1st points to the beginning of the result array and the 2nd points to the end.
3. Loop through the input array:
   If the current element is even, store this from the beginning of the result array and move 1st pointer;
   Else store this from the end of the result array and move 2nd pointer.
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> result (n, 0);
        int start = 0, end = n-1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                result[start] = nums[i];
                start++;
            }
            else
            {
                result[end] = nums[i];
                end--;
            }
        }
        return result;
    }
};