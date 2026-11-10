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
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> s;
        for(int i = 0; i < intervals.size(); i++) {
            s.push({intervals[i].start, 1});
            s.push({intervals[i].end, -1});
        }
        int maxima = 0, curr = 0;
        while(!s.empty()) {
            auto [num, meet] = s.top(); s.pop();
            curr += meet;
            maxima = max(maxima, curr);
        }
        return maxima;
    }
};
