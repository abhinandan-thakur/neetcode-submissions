class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> query;
        for(int i = 0; i < queries.size(); i++) query.push_back({queries[i], i});
        sort(query.begin(), query.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ind = 0;
        vector<int> ans(query.size(), -1);
        for(auto [q, index]: query) {
            while(ind < intervals.size() && intervals[ind][0] <= q) {
                pq.push({intervals[ind][1]-intervals[ind][0]+1, intervals[ind][1]});
                ind++;
            }
            while(!pq.empty() && pq.top().second < q) pq.pop();
            if(!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }
        return ans;
        
    }
};
