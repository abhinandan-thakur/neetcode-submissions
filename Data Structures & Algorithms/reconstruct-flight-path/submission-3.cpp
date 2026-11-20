class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> traversal;
    void dfs(string node) {
        while(!adj[node].empty()) {
            string nei = adj[node].top(); adj[node].pop();
            dfs(nei);
        }
        traversal.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets) {
            string from = ticket[0];
            string to = ticket[1];
            adj[from].push(to);
        }
        dfs("JFK");
        reverse(traversal.begin(), traversal.end());
        return traversal;
    }
};
