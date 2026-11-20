class TrieNode {
    public:
        TrieNode *children[26];
        bool wordEnd;
        TrieNode() {
            for(int i = 0; i < 26; i++) this->children[i] = nullptr;
            wordEnd = false;
        }
};
class Solution {
private:
    TrieNode *root;
    void build(string word) {
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i]-'a';
            if(curr->children[index] == nullptr) curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->wordEnd = true;
    }
    vector<pair<int,int>> nei = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<string> ans;
    vector<vector<bool>> visited;
    vector<vector<char>> board;
    int m, n;
    void dfs(int row, int col, TrieNode *curr, string s = "") {
        visited[row][col] = true;
        if(curr->wordEnd) {
            ans.push_back(s);
            curr->wordEnd = false;
        }
        for(auto [dr, dc]: nei) {
            int nr = dr + row;
            int nc = dc + col;
            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if(visited[nr][nc]) continue;
            int index = board[nr][nc]-'a';
            if(curr->children[index] == nullptr) continue;
            dfs(nr, nc, curr->children[index], s+board[nr][nc]);
        }
        visited[row][col] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        this->board = board;
        for(auto word: words) build(word);
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                TrieNode *curr = root;
                int index = board[row][col]-'a';
                if(curr->children[index] == nullptr) continue;
                dfs(row, col, curr->children[index], string(1, board[row][col]));
            }
        }
        return ans;
    }
};
