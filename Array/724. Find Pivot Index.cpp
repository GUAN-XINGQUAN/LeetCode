class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // no edge case because nums is guaranteed to be nonempty array
        // get the total of the entire array
        int total = 0;
        for (int i = 0; i <nums.size(); i++)
            total += nums[i];
        // move the candidate index
        int index = 0, leftSum = 0, rightSum = total - nums[0];
        while (index < nums.size())
        {
            if (index > 0)
            {    
                leftSum += nums[index-1];
                rightSum = rightSum - nums[index];
            }
            if (leftSum == rightSum)
                return index;
            index++;
        }
        return -1;
    }
};


/*
    0   1   2   3   4   5
    1   7   3   6   5   6
    0   1   8   11  17  22  28
    
   
    0: 0 vs. 27

    1: 1 vs. 21

    2: 8 vs. 06

    3: 11 vs. 11


    total = 28

    index = 0
    leftSum = 0
    rightSum = 28

    index = 1
    leftSum += nums[index-1]
    rightSum -= leftSum - nums[index]

    if leftSum == rightSum

*/