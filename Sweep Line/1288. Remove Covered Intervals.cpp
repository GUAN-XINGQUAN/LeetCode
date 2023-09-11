/*
Sort intervals by starting time: smaller starting time goes first; if both  have identical starting time, then the one with larger ending time goes first.
Why? As long as each interval is ranked by starting time, we just need to check if the later element's ending time is less than the previous element's ending time. If so, remove the later element.
*/

bool compare(vector<int>& vec1, vector<int>& vec2)
{
    if (vec1[0] < vec2[0])
        return true;
    else if (vec1[0] == vec2[0])
        return vec1[1] > vec2[1];
    else
        return false;
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int end = intervals[0][1], count = 0;
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][1] <= end)
                count++;
            else
                end = intervals[i][1];
        }
        return intervals.size() - count;
    }
};