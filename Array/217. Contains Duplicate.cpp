class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (numSet.count(nums[i]) != 0)
                return true;
            numSet.insert(nums[i]);
        }
        return false;
    }
};