// brute force solution
// time O(n^3)
// space O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int s = 0;
                for (int k = i; k <= j; k++)
                    s += nums[k];
                if (s >= target)
                    result = min(result, j - i + 1);
            }
        }
        return result==INT_MAX ? 0 : result;
    }
};


// optimized brute force solution
// time O(n^2)
// space O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // construct the prefix sum array
        int result = INT_MAX, n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        // retrieve the sum of subarray from i to j based on the prefix sum array
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int s = prefixSum[j] - prefixSum[i] + nums[i];
                if (s >= target)
                {    
                    result = min(result, j - i + 1);
                    break;
                }
            }
        }
        return result==INT_MAX ? 0 : result;
    }
};


// binary search
// In the solution above, we need to calculate the subarray sum from index i to index j:
// prefixSum[j] - prefixSum[i] + nums[i] >= target 
// Be aware that prefixSum is a non-descending array, so inequation above can be converted to:
// prefixSum[i] - nums[i] + target <=  prefixSum[j]
// we can use binary search to find index j that satisfies the above inequation.
// time O(n log n)
// space O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX, n = nums.size();
        // construct a prefix sum array
        vector<int> prefixSum (n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        for (int i = 0; i < n; i++)
        {
            // for each index i, we want to find the subarray sum prefixSum[j] - prefixSum[i] + nums[i] >= target
            // why not find: prefixSum[j] >= prefixSum[i] - nums[i] + target
            // do not forget prefixSum is non-decreasing order and we can use binary search
            auto it = lower_bound(prefixSum.begin()+i, prefixSum.end(), prefixSum[i] - nums[i] + target);
            if (it != prefixSum.end())
            {
                int index = it - prefixSum.begin();
                result = min(result, index - i + 1);
            }
        }
        return result==INT_MAX ? 0 : result;
    }       
};

