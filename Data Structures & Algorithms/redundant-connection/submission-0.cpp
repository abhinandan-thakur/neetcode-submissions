class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> order(n+1, 0);
        vector<vector<int>> adj(n+1);
        vector<bool> visited(n+1, false);
        queue<int> q;
        for(auto &edge: edges) {
            order[edge[0]]++;
            order[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 1; i <= n; i++) {
            if(order[i] == 1) {
                q.push(i);
                visited[i] = true;
            }
        }
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(auto nei: adj[node]) {
                if(visited[nei]) continue;
                order[nei]--;
                if(order[nei] == 1) {
                    q.push(nei);
                    visited[nei] = true;
                }
            }
        }
        int u = -1, v= -1;
        for(auto &edge: edges) {
            if(!visited[edge[0]] && !visited[edge[1]]) {
               u = edge[0];
               v = edge[1]; 
            }
        }
        return {u, v};
    }
};
