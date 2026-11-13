class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> route;
    void recursion(string node) {
        while(!adj[node].empty()) {
            string nei = adj[node].top();
            adj[node].pop();
            recursion(nei);
        }
        route.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &ticket: tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        recursion("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};
