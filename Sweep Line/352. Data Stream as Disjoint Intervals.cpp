/*
We need a data structure to maintain the inserted values in the ascending order.
Then whenever we need to retrieve intervals, we just need to loop through this data structure and get the consecutive numbers.
Such a data structure should be self-balancing binary search tree. In C++, it should be std::set
*/

class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        values.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if (values.empty())
            return {{}};
        vector<vector<int>> intervals;
        int left = -1, right = -1;
        for (std::set<int>::iterator it = values.begin(); it != values.end(); it++) {
            if (left < 0) {
                left = *it;
                right = *it;
            } else if (*it == right + 1) {
                right = *it;
            } else {
                intervals.push_back({left, right});
                left = *it;
                right = *it;
            }
        }
        intervals.push_back({left, right});
        return intervals;
    }
private:
    std::set<int> values;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */