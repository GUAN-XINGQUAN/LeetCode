/*
Think about this problem as "finding the maximum number of elements such that they don't have overlaps".
To facilitate our thinking, let's use a new result array to store the non-overlapping elements and we want to result.length as large as possible.
We sort the intervals by starting time and loop through each element.
If the current element has no overlap with last element in result array
    push current element into result
otherwise
    we drop the current one.
    why? because the last one in result array ends earlier than current one.
    we want to have as many as elements coming into result array, so we should keep the meeting that ends as early as possible.
Once we find the final non-overlapping intervals. The number of removed interval = intervals.size() - resultArray.size()

To optimize this solution, we don't need to store the entire result array. Instead, we just need to keep track the ending time of the last element inside the result array.
*/

// bool compare(vector<int>& vec1, vector<int>& vec2)
// {
//     if (vec1[0] < vec2[0])
//         return true;
//     else if (vec1[0] == vec2[0])
//         return vec1[1] < vec2[1];
//     else
//         return false;
// }

bool compare(vector<int>& vec1, vector<int>& vec2)
{
    return vec1[1] < vec2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= result.back()[1])
                result.push_back(intervals[i]);
        }
        return intervals.size() - result.size();
    }
};