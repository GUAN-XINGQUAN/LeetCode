/*
sort the intervals by the each pair's 1st element
create a new array to store result
push the 1st pair into the result array
loop through each pair in the intervals
if the current pair's 1st element <= result array's last pair's 2nd element:
    change the result array's last pair's 2nd element to MAX(2nd element, 1st element)
else
    directly push each pair into result array
time: O(n log n)
*/

bool compare(vector<int>& vec1, vector<int>& vec2)
{
    return vec1[0] < vec2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= result.back()[1])
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};