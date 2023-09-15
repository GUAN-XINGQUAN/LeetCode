/*
This is a typical sweep line problem:
1. Get all critical location point where the building starts or ends
2. Loop over each critical point and get the maximum height across all buildings
3. If the maximum height is different from previous one, save that.
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        unordered_set<int> criticalLocation;
        for (vector<int> eachBuilding : buildings)
        {
            criticalLocation.insert(eachBuilding[0]);
            criticalLocation.insert(eachBuilding[1]);
        }
        vector<int> critical {criticalLocation.begin(), criticalLocation.end()};
        sort(critical.begin(), critical.end(), less<int>());
        vector<vector<int>> result;
        for (size_t i = 0; i < critical.size(); i++)
        {
            int maxHeight = 0;
            for (size_t j = 0; j < buildings.size(); j++)
            {
                if (buildings[j][0] <= critical[i] && buildings[j][1] > critical[i] && buildings[j][2] > maxHeight)
                    maxHeight = buildings[j][2];
            }

            if (result.empty() || maxHeight != result.back()[1])
                result.push_back({critical[i], maxHeight});
        }
        return result;
    }
};