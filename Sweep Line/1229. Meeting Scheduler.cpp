/*
Be aware that slots1 and slots2 are not sorted, so we should sort them based on the starting time.
Then, we need to use two pointers to scan over them.
For each pair (one from slots1 and the other from slots2), we need to get their common time. Their common time may be negative, which means no common time. If commno time > duration, return it.
Regarding how we move two pointers: we always move the one that ends earlier.
*/

bool compare(vector<int>& vec1, vector<int>& vec2) 
{
    // we want smaller one to go left end
    return vec1[0] < vec2[0];
}

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), compare);
        sort(slots2.begin(), slots2.end(), compare);
        int i = 0, j = 0;
        while (i < slots1.size() && j < slots2.size()) 
        {
            int startTime = max(slots1[i][0], slots2[j][0]);
            int endTime = min(slots1[i][1], slots2[j][1]);
            int commonTime = endTime - startTime;
            if (commonTime >= duration)
                return {startTime, startTime+duration};
            else if (slots1[i][1] < slots2[j][1])
                i++;
            else
                j++;
        }
        return {};
    }
};

/*
    duration=10
    i       i
    10,50;  60,120; 140,210
    0,15;   60,70
            j

    startTime = 60
    endTime = 70
    commonTime = 10
*/