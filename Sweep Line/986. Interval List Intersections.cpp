/*
Use two pointers and one for firstList and the other for secondList.
Compare each pair from two lists:
    If they have overlap:
        save overlap and move the point that has smaller ending element
    Otherwise, still move the pointer that has smaller ending element
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < firstList.size() & j < secondList.size())
        {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            int common = end - start;
            if (common >= 0)
                result.push_back({start, end});
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return result;
    }
};

