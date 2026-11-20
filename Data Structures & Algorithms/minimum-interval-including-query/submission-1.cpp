class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> arr;
        for(int i = 0; i < queries.size(); i++) arr.push_back({queries[i], i});
        sort(arr.begin(), arr.end());
        int index = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> ans(queries.size(), -1);
        for(auto [query, ind]:arr) {
            while(index < intervals.size() && intervals[index][0] <= query) {
                pq.push({intervals[index][1]-intervals[index][0]+1, intervals[index][1]});
                index++;
            }
            while(!pq.empty() && pq.top().second < query) pq.pop();
            if(!pq.empty()) ans[ind] = pq.top().first;
        }
        return ans;
    }
};
