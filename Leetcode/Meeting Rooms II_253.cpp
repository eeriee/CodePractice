/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//my first thought. not fast 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto iv: intervals){
            pq.push(make_pair(iv.end, iv.start));
        }
        int room = 0;
        vector<int> ends;
        while(!pq.empty()){
            auto meeting = pq.top();
            pq.pop();
            if(room == 0){
                ends.push_back(meeting.first);
                ++room;
            }else{
                bool add = true;
                sort(ends.begin(), ends.end());
                for(int i = room-1; i >= 0; --i){
                    if(meeting.second >= ends[i]){
                        ends[i] = meeting.first;
                        add = false;
                        break;
                    }
                }
                
                if(add){
                    ++room;
                    ends.push_back(meeting.first);
                }
            }
        }
        return room;
    }
};
//fast solution. O(nlogn)
class Solution {
public:
    static bool cmp(Interval i1, Interval i2){
        return i1.start < i2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        int n = intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> endtime;
        endtime.push(intervals[0].end);
        
        for(int i = 1; i < n; ++i){
            int minEnd = endtime.top();
            if(intervals[i].start >= minEnd){
                endtime.pop();
            }
            endtime.push(intervals[i].end);
        }
        return endtime.size();
    }
};

//smart but not fast. 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for(auto iv: intervals){
            ++mp[iv.start];
            --mp[iv.end];
        }
        int usingRoom = 0, totalRoom = 0;
        for(auto item: mp){
            usingRoom += item.second;
            totalRoom = max(usingRoom, totalRoom);
        }
        return totalRoom;
    }
};