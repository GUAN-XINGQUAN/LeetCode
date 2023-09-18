/*
We can use a fictious tree to help us find all permutations.
At i-th layer, we try to use all numbers in i-th spot in the final permutations. The permutations is constructed by connecting root to each leaf.

For example, nums = [1,2,3]

         []
    /    |   \
    1    2    3
   / \   | |  |  \
  2   3  1 3  1   2
  |   |  | |  |   |
  3   2  3 1  2   1

[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> eachPerm;
        vector<vector<int>> allPermutations;
        unordered_set<int> s;
        backtracking(nums, eachPerm, allPermutations, s);
        return allPermutations;
    }
    void backtracking(vector<int>& nums, vector<int>& eachPerm, vector<vector<int>>& allPermutations, unordered_set<int>& s)
    {
        if (eachPerm.size() >= nums.size())
        {
            allPermutations.push_back(eachPerm);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.count(nums[i]) != 0)
                continue;
            eachPerm.push_back(nums[i]);
            s.insert(nums[i]);
            backtracking(nums, eachPerm, allPermutations, s);
            eachPerm.pop_back();
            s.erase(nums[i]);
        }
    }
};