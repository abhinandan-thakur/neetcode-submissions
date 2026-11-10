/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            if(a.end == b.end) {
                return a.start < b.start;
            }
            return a.end < b.end;
        });
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i-1].end > intervals[i].start) return false;
        }
        return true;
    }
};
