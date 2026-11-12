class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<pair<int,int>>> adj(m);
        for(int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x2-x1) + abs(y2-y1);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        int ans = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0,0});
        while(!minHeap.empty()) {
            auto [dist, node] = minHeap.top(); minHeap.pop();
            if(visited.count(node)) continue;
            visited.insert(node);
            ans += dist;
            for(auto &nei: adj[node]) {
                if(visited.count(nei.second)) continue;
                minHeap.push({nei.first, nei.second});
            }
        }
        return ans;
    }
};
