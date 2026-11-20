class Solution {
private:
    bool differenceIs1(string a, string b) {
        int count = 0, index = 0;
        while(index < a.size() && index < b.size() && count < 2) {
            if(a[index] != b[index]) count++;
            index++;
        }
        return count==1; 
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        int length = 1;
        vector<string> vec = wordList;
        vec.push_back(beginWord);
        unordered_map<string, vector<string>> adj;
        for(int node = 0; node < vec.size(); node++) {
            for(int nei = node+1; nei < vec.size(); nei++) {
                if(differenceIs1(vec[node], vec[nei])) {
                    adj[vec[node]].push_back(vec[nei]);
                    adj[vec[nei]].push_back(vec[node]);
                }
            }
        }

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                    string node = q.front(); q.pop();
                    if(node == endWord) return length;
                    for(auto nei: adj[node]) {
                    if(visited.count(nei)) continue;
                    q.push(nei);
                    visited.insert(nei);
                }
            }
            length++;
        }
        return 0;
        
    }
};
