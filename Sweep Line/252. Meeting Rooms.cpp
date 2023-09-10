// sort the intervals based on their starting time
// check every adjacent interval
// if the previous interval 2nd element >= current interval 1st element --> conflict
// after find the entire array of intervals and no conflict --> can attend all meetings
// time: O(n log n)

bool compare(vector<int>& vec1, vector<int>& vec2)
{
    return vec1[0] < vec2[0];
}

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        for(size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i-1][1] > intervals[i][0])
                return false;
        }
        return true;
    }
};