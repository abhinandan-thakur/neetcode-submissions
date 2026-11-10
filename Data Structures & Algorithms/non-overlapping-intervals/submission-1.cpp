class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int prev0 = intervals[0][0];
        int prev1 = intervals[0][1];
        int toDelete = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(prev1 > intervals[i][0]) {
                toDelete++;
                prev1 = min(prev1, intervals[i][1]);
            }
            else {
                prev0 = intervals[i][0];
                prev1 = intervals[i][1];
            }
        }
        return toDelete;
    }
};
