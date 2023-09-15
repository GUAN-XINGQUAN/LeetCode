/*
Actually, we don't care which schedule belongs to who; what we really care is the gap between all intervals.

Put all intervals into a single array and sort by starting time (priority queue)
We grab one interval from the queue and denote as current interval.
Compare this current interval with the next pop-out element in the queue.
If current interval has overlap with next element, extend current interval to cover next element
Otherwise, the gap between current interval and next element should be one of the result.
Repeat this process until we trace through all elements in the queue.
*/


/*
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[0] > b[0];
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (int i = 0; i < schedule.size(); i++)
        {
            for (int j = 0; j < schedule[i].size(); j++)
            {
                pq.push({schedule[i][j].start, schedule[i][j].end});
            }
        }
        vector<int> cur = pq.top();
        pq.pop();
        vector<Interval> result;
        while(!pq.empty())
        {
            if (cur[1] >= pq.top()[0])
            {
                cur[1] = max(cur[1], pq.top()[1]);
                pq.pop();
            }
            else
            {
                Interval temp = Interval(cur[1], pq.top()[0]);
                result.push_back(temp);
                cur = pq.top();
                pq.pop();
            }
        }
        return result;
    }
};