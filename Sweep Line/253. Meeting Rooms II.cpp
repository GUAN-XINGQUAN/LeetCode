/*
let's count the number of required meeting room at each time point
At time t, if a meeting starts, the count plus 1. If a meeting ends, the count minus 1.
After we loop through each time being that either a meeting starts or ends, then we can get the maximum number of required meeting rooms.
Caveat: if meeting i ends and meeting j starts at the same time.
We should put meeting j before meeting i because meeting i can use meeting j room.

time: O(n log n)
*/

bool compare(vector<int>& vec1, vector<int>& vec2)
{
    if (vec1[0] < vec2[0])
        return true;
    else if (vec1[0] == vec2[0])
        return vec1[1] < vec2[1];
    else
        return false;
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<vector<int>> timeRoom;
        for (size_t i = 0; i < intervals.size(); i++)        
        {
            timeRoom.push_back({intervals[i][0], 1});
            timeRoom.push_back({intervals[i][1], -1});
        }
        sort(timeRoom.begin(), timeRoom.end(), compare);
        int result = INT_MIN, count = 0;
        for (size_t i = 0; i < timeRoom.size(); i++)
        {
            count += timeRoom[i][1];
            result = max(result, count);
        }
        return result;
    }
};