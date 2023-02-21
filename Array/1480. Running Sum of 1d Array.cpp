class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Problem statement mentions that the nums cannot be empty
        // so the empty check is skipped
        int n = nums.size();
        vector<int> runSums (n, 0);
        runSums[0] = nums[0];
        for (int i = 1; i < n; i++)
            runSums[i] = runSums[i-1] + nums[i];
        return runSums; 
    }
};