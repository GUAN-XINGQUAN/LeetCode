/*
four scenarios:
1 - current interval has no overlapping with toBeRemoved
2 - current interval is within toBeRemoved
3 - current interval is longer than toBeRemoved at left side
4 - current interval is longer than toBeRemoved at right side
*/
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> result;
        for (vector<int> eachInterval : intervals)
        {
            // no overlapping at all
            if (eachInterval[1] <= toBeRemoved[0] || eachInterval[0] >= toBeRemoved[1])
                result.push_back(eachInterval);
            else
            {
                // current interval is longer at left side
                if (eachInterval[0] < toBeRemoved[0])
                    result.push_back({eachInterval[0], toBeRemoved[0]});
                // current interval is longer at right side
                if (eachInterval[1] > toBeRemoved[1])
                    result.push_back({toBeRemoved[1], eachInterval[1]});
                // otherwise --> do nothing (we don't save any other cases)
            }
        }
        return result;
    }
};