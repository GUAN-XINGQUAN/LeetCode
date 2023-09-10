
/*
be aware that newInterval is only one interval

approach #1:
save newInterval into intervals
then this problem is converted to the "merge intervals" problem
rest is to use the solution for "merge intervals" problem

this solution does not use the feature that intervals is already sorted based on the starting element and thus takes longer time.

approach #2:
subarray I: loop through each pair in the intervals until current pair ending element >= newInterval starting element (this means where overlapping occurs)
subarray II: continue to loop through the rest elements until the current pair starting element >= newInterval ending element (this means where overlapping ends)
subarray III: the rest pairs in the intervals

save subarray I to the result array
process subarray II to such that newInterval covers the left and right boundary for all overlapping elements. Then save this newInterval into result array
save subarray III to the result array
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};
        vector<vector<int>> result;
        size_t idx = 0, n = intervals.size();
        while (idx < n && intervals[idx][1] < newInterval[0])
        {    
            result.push_back(intervals[idx]);
            idx++;
        }
        while (idx < n && intervals[idx][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[idx][0], newInterval[0]);
            newInterval[1] = max(intervals[idx][1], newInterval[1]);
            idx++;
        }
        result.push_back(newInterval);
        while (idx < n)
        {
            result.push_back(intervals[idx]);
            idx++;
        }
        return result;
    }
};