class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // vector<int> result (nums.size(), 0);
        if (nums.empty())
            return 0;
        // result[0] = nums[0];
        int finalMax = nums[0];
        int currentMax = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (currentMax+nums[i] > nums[i])
                currentMax = currentMax+nums[i];
            else
                currentMax = nums[i];
            finalMax = max(currentMax, finalMax);
        }    
        return finalMax;
    }
};