/*

*/

// two pointers
// time O(n)
// space O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while (left <= right)
        {
            int s = numbers[left] + numbers[right];
            if (s == target)
                return vector<int> {left+1, right+1};
            else if (s < target)
                left++;
            else
                right--;
        }
        return vector<int> {-1, -1};
    }
};