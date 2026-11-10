class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int prev0 = intervals[0][0];
        int prev1 = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(prev1 >= intervals[i][0]) {
                prev1 = max(prev1, intervals[i][1]);
                prev0 = min(prev0, intervals[i][0]);
            }
            else {
                ans.push_back({prev0, prev1});
                prev0 = intervals[i][0];
                prev1 = intervals[i][1];
            }
        }
        ans.push_back({prev0, prev1});
        return ans;
    }
};
