/*
This problem is similar to 78 subsets.
The only difference is that this problem allows duplicated elements in the given array.

For example, nums = [1,2,2].
We could construct a decision tree by starting an empty set and determine whether we should include i-th element in each layer.

                []
            /          \
          [1]               []
       /       \             |      \
     [1,2]      [1]         [2]     []
   /    \        |    \      |    \   |   \
[1,2,2]  [1,2]  [1,2]  [1]  [2,2] [2] [2]  []

We could see that in the leaft nodes, the 3rd is the same as 2nd leaf ([1,2]).
Similarly, the 7th leaf is the same as 6th leaf ([2]).

We can do pruning:
(1) if we decide to include i-th element, we follow the same approach in Problem 78.
(2) if we skip the i-th element, we need to skip all the elements whose values equal to i-th element.
In this case, our tree looks like below:

                []
            /          \
          [1]               []
       /       \             |       \
     [1,2]      [1]         [2]       []
   /    \             \      |    \      \
[1,2,2]  [1,2]        [1]  [2,2] [2]      []
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> eachSubset;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end(), less<int>());  // sort to make removing same elements easier
        backtracking(nums, eachSubset, result, 0);
        return result;
    }
    void backtracking(vector<int>& nums, vector<int>& eachSubset, vector<vector<int>>& subset, int start)
    {
        if (start >= nums.size())
        {
            subset.push_back(eachSubset);
            return;
        }
        // include i-th element
        eachSubset.push_back(nums[start]);
        backtracking(nums, eachSubset, subset, start+1);
        eachSubset.pop_back();

        // exclude i-th element
        while (start + 1 < nums.size() && nums[start] == nums[start+1])
            start++;
        backtracking(nums, eachSubset, subset, start+1);
    }
};