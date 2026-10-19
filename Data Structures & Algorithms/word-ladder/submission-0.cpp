class Solution {
private:
    unordered_map<string, vector<string>> neighbors;
    bool isNei(string a, string b) {
        int exceptions = 0;
        int i = 0;
        for(i = 0; i < min(a.size(), b.size()); i++) {
            if(a[i] != b[i]) exceptions++;
            if(exceptions > 1) return false;
        }
        for(int j = i; j < a.size(); j++) exceptions++;
        for(int k = i; k < b.size(); k++) exceptions++;
        if(exceptions != 1) return false;
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // cout << "hellop" << endl;
        vector <string> all = wordList;
        all.push_back(beginWord);
        for(int from = 0; from < all.size(); from++) {
            for(int to = from+1; to < all.size(); to++) {
                if(!isNei(all[from], all[to])) continue;
                neighbors[all[from]].push_back(all[to]);
                neighbors[all[to]].push_back(all[from]);
            }
        }
        queue<string> q;
        int steps = 1;
        unordered_map<string, bool> visited;
        q.push(beginWord);
        visited[beginWord] = true;
        while(!q.empty()) {
            int levelSize = q.size();
            while(levelSize--) {
                string node = q.front(); q.pop();
                // cout << endl << node << "---node---" << endl;
                if(node == endWord) return steps;
                vector<string> nei = neighbors[node];
                for(auto str: nei) {
                    if(visited[str]) continue;
                    q.push(str);
                    visited[str] = true;
                    // cout << str << " , ";
                }
            }
            steps++;
        }
        return 0;
    }
};
