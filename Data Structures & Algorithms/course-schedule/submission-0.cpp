class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses,0);
        vector<vector<int>> adj(numCourses);
        unordered_set<int> visited;
        for(int node = 0; node < numCourses; node++) visited.insert(node);
        for(auto &prerequisite: prerequisites) {
            int todo = prerequisite[1];
            int toget = prerequisite[0];
            inorder[toget]++;
            adj[todo].push_back(toget);
        }
        queue<int> q;
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] != 0) continue;
            q.push(i);
            visited.erase(i);
        }
        // for(auto s: visited) cout << s << endl;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(auto nei: adj[node]) {
                inorder[nei]--;
                if(!visited.count(nei)) continue;
                if(inorder[nei] == 0) {
                    q.push(nei);
                    visited.erase(nei);
                }
            }

        }
        // for(auto s: visited) cout << s << endl;
        if(visited.size() == 0) return true;
        return false;
    }
};
