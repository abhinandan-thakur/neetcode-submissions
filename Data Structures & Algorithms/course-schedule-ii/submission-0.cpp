class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto &prerequisite: prerequisites) {
            inorder[prerequisite[0]]++;
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        queue<int> q;
        vector<int> visited;
        for(int node = 0; node < numCourses; node++) {
            if(inorder[node] == 0) {
                q.push(node);
                cout << node << endl;
            }
        }
        while(!q.empty()) {
            int node = q.front(); q.pop();
            visited.push_back(node);
            for(auto nei: adj[node]) {
                inorder[nei]--;
                if(inorder[nei] == 0) q.push(nei); 
            }

        }
        for(auto check: inorder) if(check > 0) return {};
        return visited;
    }
};
