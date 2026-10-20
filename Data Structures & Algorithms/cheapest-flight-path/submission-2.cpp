class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights) adj[f[0]].push_back({f[2], f[1]});
        vector<int> steps(n, INT_MAX);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0,0,src});
        while(!pq.empty()) {
            auto [wt, st, node] = pq.top(); pq.pop();
            if(node == dst) return wt;
            if(st > k) continue;
            if(st >= steps[node]) continue;
            steps[node] = st;
            for(auto [nwt, nei]: adj[node]) {
                pq.push({wt+nwt, st+1, nei});
            }
        }
        return -1;
    }
};
