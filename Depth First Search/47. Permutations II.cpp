/*
This is similar to 46. Permutations. The only difference is that this problems allow duplicated elements.

Tree for nums = [1,1,2]
            []                   layer-0
        /    |     \             
       1     1      2            layer-1
     / |    /\      | \
    1  2   1  2     1  1         layer-2
   /   |   |  |     |  |
   2   1   2  1     1  1         layer-3
[1,1,2], [1,2,1], [1,1,2], [1,2,1], [2,1,1], [2,1,1]

We notice that, to remove duplicates, we should not use the same elements twice.
In the tree, since the first-layer left child uses "1", then we should skip the first-layer middle child "1" because it is repeating the previous permutations.
Similarly, In the rightmost branch of layer-2, we should skip the rightmost child "1" as well because we already tried "1" in its left sibling.

By adopting method above, the tree looks like:
            []                   layer-0
        /         \             
       1           2             layer-1
     / |            | 
    1  2            1            layer-2
   /   |            |  
   2   1            1            layer-3
[1,1,2], [1,2,1], [1,1,2], [1,2,1], [2,1,1], [2,1,1]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> eachPerm;
        vector<vector<int>> allPerm;
        int n = nums.size();
        vector<bool> visited (n, false);
        backtracking(nums, eachPerm, allPerm, visited);
        return allPerm;
    }
    void backtracking(vector<int>& nums, vector<int>& eachPerm, vector<vector<int>>& allPerm, vector<bool>& visited)
    {
        // base case
        if (eachPerm.size() >= nums.size())
        {
            allPerm.push_back(eachPerm);
            return;
        }
        // derivative case
        for (int i = 0; i < nums.size(); i++)
        {
            // we shall not use same elements twice
            if (visited[i] == true)
                continue;
            // do pruning to avoid duplicates
            if (i > 0 && nums[i] == nums[i-1] && visited[i-1] == true)
                continue;
            // all other cases shall use that element
            eachPerm.push_back(nums[i]);
            visited[i] = true;
            backtracking(nums, eachPerm, allPerm, visited);
            eachPerm.pop_back();
            visited[i] = false;
        }

    }
};