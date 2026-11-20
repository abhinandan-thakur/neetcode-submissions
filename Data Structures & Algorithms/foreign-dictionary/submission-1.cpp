class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, int> inorder;
        unordered_map<char, unordered_set<char>> adj;
        for(auto word : words) for(auto c : word) inorder[c] = 0;

        for(int i = 0; i+1 < words.size(); i++) {
            int len = min(words[i].size(), words[i+1].size());
            if(words[i].size() > words[i+1].size() && words[i].substr(0, len) == words[i+1]) return "";
            for(int j = 0; j < len; j++) {
                if(words[i][j] == words[i+1][j]) continue;
                if(adj[words[i][j]].count(words[i+1][j])) break;
                adj[words[i][j]].insert(words[i+1][j]);
                inorder[words[i+1][j]]++;
                break;
            }
        }

        queue<char> q;
        for(auto [ch, order]: inorder) {
            if(order == 0) q.push(ch);
        }
        string ans = "";
        while(!q.empty()) {
            char c = q.front(); q.pop();
            ans += c;
            for(auto nei:adj[c]) {
                if(--inorder[nei] == 0) q.push(nei);
            }
        }
        if(ans.size() != inorder.size()) return "";
        return ans;
    }
};
