class Solution {
private:
    int count = 0;
    vector<bool> visited;
    vector<vector<int>> adj;
    void dfs(int node) {
        visited[node] = true;
        for(auto nei : adj[node]) {
            if(visited[nei]) continue;
            dfs(nei);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, false);
        adj = vector<vector<int>>(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            dfs(i);
            count++;
        }
        return count;
    }
};
