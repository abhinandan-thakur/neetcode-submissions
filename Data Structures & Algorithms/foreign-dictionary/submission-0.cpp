class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for(auto &word: words) {
            for(auto &alpha: word) {
                adj[alpha] = unordered_set<char>();
                indegree[alpha] = 0;
            }
        } 
        for(int i = 0; i+1 < words.size(); i++) {
            int len = min(words[i].size(), words[i+1].size());
            if(words[i].size() > words[i+1].size() && words[i].substr(0, len) == words[i+1]) return "";
            for(int j = 0; j < len; j++) {
                if(words[i][j] != words[i+1][j]) {
                    if(!adj[words[i][j]].count(words[i+1][j])) {
                        adj[words[i][j]].insert(words[i+1][j]);
                        indegree[words[i+1][j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        // for(auto &[key val]: indegree) if(val == 0) q.push(key);
        for(auto &[key,val]: indegree) if(val == 0) q.push(key);   // comma added
        string res;
        while(!q.empty()) {
            char curr = q.front(); q.pop();
            res += curr;
            for(auto nei: adj[curr]) {
                if(--indegree[nei] == 0) q.push(nei);
            }
        }
        return res.size() == indegree.size() ? res : "";

    }
};
