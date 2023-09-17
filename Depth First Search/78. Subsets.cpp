/*
Typical backtracking problem:

We can construct a fictious decision tree where the leaf nodes are all subsets.
At each layer, we need to deterine whethe we should include i-th element or not.

For example, nums = [1,2]
Visualization would be:
        []                start with empty set
    /       \
   [1]       []           whether we should include 1st element in nums
  /   \     /  \
[1,2]  [1] [2]  []        whether we should include 2nd element in nums


Alternatively, we can construct the decision tree where each node (including both leaf and internal nodes) is the subset.
At i-th layer, we just need to enumerate all potential subset whose size is i.

        []                start with empty set  
    /       \ 
   [1]      [2]           add all potential element for the subset whose size is 1
  /
[1,2]                     add all potential element for the subset whose size is 2

Both implementations are provided below.
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> oneSubset;
        vector<vector<int>> result;
        backtracking(nums, oneSubset, result, 0);
        return result;
    }
    void backtracking(vector<int>& nums, vector<int>& oneSubset, vector<vector<int>>& subset, int start)
    {
        // base case
        if (start >= nums.size())
        {
            subset.push_back(oneSubset);   
            return;
        }
        // include start-th element
        oneSubset.push_back(nums[start]);
        backtracking(nums, oneSubset, subset, start+1);
        oneSubset.pop_back();

        // exclude start-th element
        backtracking(nums, oneSubset, subset, start+1);
    }
    // the backtracking function can also be implemented using the following approach
    void backtracking2(vector<int>& nums, vector<int>& oneSubset, vector<vector<int>>& subset, int start)
    {
        subset.push_back(oneSubset);   

        for (int i = start; i < nums.size(); i++)
        {
            oneSubset.push_back(nums[start]);
            backtracking(nums, oneSubset, subset, i+1);
            oneSubset.pop_back();
        }
    }
};