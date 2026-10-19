class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int> time: times) {
            int from = time[0];
            int to = time[1];
            int weight = time[2];
            adj[from].push_back({weight, to});
        }
        pq.push({0, k});
        distance[k] = 0;
        while(!pq.empty()) {
            auto [dist, node] = pq.top(); pq.pop();
            if(dist > distance[node]) continue;
            for(auto [newDist, nei]: adj[node]) {
                int nd = dist+newDist;
                if(nd >= distance[nei]) continue;
                pq.push({nd, nei});
                distance[nei] = min(nd, distance[nei]);
            }
        }
        for(int i = 1; i <= n; i++) if(distance[i] == INT_MAX) return -1;
        return *max_element(distance.begin()+1, distance.end());
    }
};
