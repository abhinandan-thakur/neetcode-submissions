class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> adj;
    bool dfs(int node, int parent = -1) {
        bool ans = true;
        visited[node] = true;
        for(auto nei: adj[node]) {
            if(nei == parent) continue;
            if(visited[nei]) return false;
            ans = ans && dfs(nei, node);
        }
        return ans;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, false);
        adj = vector<vector<int>>(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        bool ans = dfs(0);
        if(ans) {
            for(int i = 0; i < visited.size(); i++) if(visited[i] == false) return false;
            return true;
        }
        return false;
    }
};
