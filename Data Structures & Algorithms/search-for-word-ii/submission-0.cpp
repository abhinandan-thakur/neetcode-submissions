class TrieNode {
    public:
    TrieNode *children[26];
    bool wordEnd;
    string word;
    TrieNode() {
        for(int i = 0; i < 26; i++) this->children[i] = nullptr;
        wordEnd = false;
    }
};
class Solution {
private:
    vector<string> result;
    TrieNode *root = new TrieNode();
    void insert(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i]-'a';
            if(node->children[index] == nullptr) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->wordEnd = true; 
        node->word = word;
    }
    void dfs(vector<vector<char>> &board, int row, int col, TrieNode *node) {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return;
        if(board[row][col] == '#') return;
        char ch = board[row][col];
        TrieNode *child = node->children[ch-'a'];
        if(!child) return;

        board[row][col] = '#';
        if(child->wordEnd) {
            result.push_back(child->word);
            child->wordEnd = false;
        }
        dfs(board, row+1, col, child);
        dfs(board, row, col+1, child);
        dfs(board, row-1, col, child);
        dfs(board, row, col-1, child);
        board[row][col] = ch;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &word: words) insert(word);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }
        return result;
    }
};
