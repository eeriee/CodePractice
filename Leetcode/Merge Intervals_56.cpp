/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty() || intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        });
        vector<Interval> res;
        int start = intervals[0].start, end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i].start > end){
                res.push_back(Interval(start, end));
                start = intervals[i].start;
            }
            end = max(end, intervals[i].end);
        }
        res.push_back(Interval(start, end));
        return res;
    }
};