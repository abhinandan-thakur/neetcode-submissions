class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[1] == b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int prev1 = intervals[0][0];
        int prev2 = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(prev2 >= intervals[i][0]) {
                prev1 = min(prev1, intervals[i][0]);
                prev2 = max(prev2, intervals[i][1]);
            }
            else {
                ans.push_back({prev1, prev2});
                prev1 = intervals[i][0];
                prev2 = intervals[i][1];
            }
        }
        ans.push_back({prev1, prev2});
        return ans;

    }
};
